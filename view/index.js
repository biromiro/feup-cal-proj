let map;

async function initMap() {
    const paths = await parseFile();
    console.log(paths)
    const mapOptions = {
        zoom: 18,
        center: { lat: 41.177155916159826, lng: -8.596591921635884 },
    };
    map = new google.maps.Map(document.getElementById("map"), mapOptions);
    draw(paths);
}

async function parseFile() {
    const data = await (await fetch("sample.json")).json();
    console.log(data);
    return data.paths;
}

function drawInitialNodes(paths, n) {
    const park =
    "images/park_icon.png";

    new google.maps.Marker({
        position: { lat: paths[n].park[0], lng: paths[n].park[1] },
        map,
        title: "Park",
        label: `P${n}`,
        icon: park
    });

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
        strokeWeight: 2,
      });
      polyline.setMap(map);
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
}

function draw(paths) {
    drawInitialNodes(paths, 0);
    drawToPark(paths, 0);
    drawToDest(paths, 0);
}

function animate() { }
