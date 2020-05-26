#!/bin/bash

set -e

VERSION=$(cat version.json | jq -r .version)
GIT_TAG=v$VERSION
git tag -a -m "tagging $GIT_TAG" $GIT_TAG
git push -u origin $GIT_TAG
pod spec lint quantumgraph.podspec
pod trunk push quantumgraph.podspec
pod spec lint Appier.podspec
pod trunk push Appier.podspec
