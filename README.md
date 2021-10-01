# Building

```
git clone git@github.com:hendore/sockets.git
cd sockets
mkdir build && cd build
cmake ..
make
```

## Webserver (TCP)
Run the built `./webserver` executable then visit `localhost:28790` in your browser or use curl to see the delivered http response.

## Broadcast server (TCP)
Run the built `./broadcastserver` executable then in another terminal use the netcat utility to open a client `nc 127.0.0.1 28790`.
Once connected, enter messages on the server and verify they are recieved in the client terminal.

## Stream server (UDP)
Run the built `./streamserver` executable then in another terminal use the netcat utility to start receiving the streamed data
`nc -u 127.0.0.1 28790` then in the netcat client window send any message to the stream server to start receiving updates.
