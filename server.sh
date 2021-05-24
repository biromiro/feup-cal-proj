cd build/view

echo "Opening http server"

python -m http.server 8080 && \
echo "Successfully opened http server" && \
echo "Access your browser to view MyJourney results!"
cd ..