cmake_minimum_required(VERSION 3.21)

project(socket_programming VERSION 1.0.0 LANGUAGES C OBJC)

add_executable(broadcastserver broadcast_server.c)
add_executable(webserver web_server.c)
add_executable(streamserver stream_server.c)
