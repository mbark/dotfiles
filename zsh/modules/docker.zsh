#!/bin/bash

function docker-cleanup() {
    # remove exited containers
    docker ps --filter status=dead --filter status=exited -aq | xargs -r docker rm -v
    # remove unused images
    docker images --no-trunc | grep '<none>' | awk '{ print $3 }' | xargs -r docker rmi
    # remove unused volumes
    docker volume ls -qf dangling=true | xargs -r docker volume rm
}

function docker-cleanall() {
    if confirm ; then
        docker rm $(docker ps -a -q)
        docker rmi $(docker images -q)
    fi
}
