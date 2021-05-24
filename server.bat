cd winbuild/view

echo "Opening http server"

python -m http.server 8000 --bind 127.0.0.1 && \
echo "Successfully opened http server" && \
echo "Access your browser to view MyJourney results!"
cd ..