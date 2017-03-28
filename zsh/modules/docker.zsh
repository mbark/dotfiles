#!/bin/bash

function docker-cleanall() {
    if confirm ; then
        docker rm $(docker ps -a -q)
        docker rmi -f $(docker images -q)
    fi
}
