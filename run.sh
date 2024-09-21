#!/bin/bash
source name.sh

echo "Running Docker container with image: ${IMAGE}"

docker images  # List available Docker images to check if ${IMAGE} was built

docker run --rm ${IMAGE} || { echo "Docker run failed"; exit 1; }
