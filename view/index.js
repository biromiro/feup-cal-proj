let map;
let forward, backward;

async function sleep(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
  }

async function initMap() {
    const paths = await parseFile();

    const mapOptions = {
        zoom: 18,
        center: { lat: paths[0].orig[0], lng: paths[0].orig[1] },
    };
    map = await new google.maps.Map(document.getElementById("map"), mapOptions);
 
    await initSymbol();

    const lines = draw(paths);
    await animate(lines);
}

async function initSymbol() {
    forward = {
        path: google.maps.SymbolPath.FORWARD_CLOSED_ARROW,
        scale: 4,
        strokeColor: "#000000",
    };
    backward = {
        path: google.maps.SymbolPath.BACKWARD_CLOSED_ARROW,
        scale: 4,
        strokeColor: "#000000",
    };
}

async function parseFile() {

    const data = await (await fetch("resources/journey.json")).json();
    console.log(data);
    return data.paths;
}

function drawParks(paths, n) {
    const infoWindow = new google.maps.InfoWindow();
    const shape = {coords: [0,0,5], type: "circle"};    
    paths[n].parks.forEach((p, idx) => {

        const marker = new google.maps.Marker({
            position: { lat: p.pos[0], lng: p.pos[1] },
            map,
            title: `P${n}-${idx}`,
        });


        if (p.pos[0] === paths[n].park[0] && p.pos[1] === paths[n].park[1]) {
            marker.setIcon("images/park_icon.png");
        } else {
            marker.setIcon("images/park_visited.png");
        }

        marker.addListener("click", () => {
            infoWindow.close();
            infoWindow.setContent(
                `<h3>${marker.getTitle()}</h1>
                 <p>ID: ${p.id} </p>
                 <p>Distance: ${p.dist} </p>
                 <p>Current capacity: ${p.currCap} </p>
                 <p>Max capacity: ${p.maxCap} </p>
                 <p>Price: ${p.price}</p>`);
            infoWindow.open(marker.getMap(), marker);
          });
      
    });


}

function drawInitialNodes(paths, n) {
    drawParks(paths, n);

    new google.maps.Marker({
        position: { lat: paths[n].orig[0], lng: paths[n].orig[1] },
        map,
        title: "Origin",
        label: `O${n}`,
    });

    new google.maps.Marker({
        position: { lat: paths[n].dest[0], lng: paths[n].dest[1] },
        map,
        title: "Destination",
        label: `D${n}`,
    });
}

function drawToPark(paths, n) {
    const edges = paths[n].origToPark.map(el => ({
        lat: el[0], lng: el[1]
    }));
    edges.unshift({lat: paths[n].orig[0], lng: paths[n].orig[1]});
    edges.push({lat: paths[n].park[0], lng: paths[n].park[1]});

    const polyline = new google.maps.Polyline({
        path: edges,
        geodesic: true,
        strokeColor: "#FF0000",
        strokeOpacity: 1.0,
        strokeWeight: 1, 
      });
      polyline.setMap(map);
    
    return polyline;
}

function drawToDest(paths, n) {
    const edges = paths[n].parkToDest.map(el => ({
        lat: el[0], lng: el[1]
    }));
    edges.unshift({lat: paths[n].park[0], lng: paths[n].park[1]});
    edges.push({lat: paths[n].dest[0], lng: paths[n].dest[1]});

    const polyline = new google.maps.Polyline({
        path: edges,
        geodesic: true,
        strokeColor: "#00FF00",
        strokeOpacity: 1.0,
        strokeWeight: 2,      
      });
      polyline.setMap(map);
      return polyline;
}

function draw(paths) {
    const car = [];
    const walk = [];
    for (let i = 0; i < paths.length; i++) {
        drawInitialNodes(paths, i);
        car.push(drawToPark(paths, i));
        walk.push(drawToDest(paths, i));   
    }
    return {
        car, walk
    };
}

async function animateLine(line, speed, reversed) {
    let count = !reversed ? 0 : 100;
    const size = await google.maps.geometry.spherical.computeLength(line.getPath())/1000;
    line.set("icons", [
        {
          icon: !reversed ? forward : backward,
          offset: "0%",
        },
      ])
    while (count <= 100 && count >= 0) {
      const icons = line.get("icons");
      icons[0].offset = count + "%";
      line.set("icons", icons);
      count += speed/size * (reversed ? -1 : 1);
      await sleep(20);
    }
    line.set("icons", []);
  }
  

async function animate(lines) {
    for (let i = 0; i < lines.car.length; i++) {
        lines.car[i].set("strokeWeight", 3);

        await animateLine(lines.car[i], 1);
        await animateLine(lines.walk[i], 0.05);
        if (i != lines.car.length - 1) await animateLine(lines.walk[i], 0.05, true);

        lines.car[i].set("strokeWeight", 1);
    }
}
