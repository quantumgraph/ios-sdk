#!/usr/bin/env groovy

pipeline {
  agent {
    label "mobile-mac-mini"
  }

  stages {
    stage('build') {
      steps {
        checkout scm
        sh '''#!/bin/bash
VERSION=`grep VERSION QGSdk.h | rev | cut -d ' ' -f1 | rev`
GIT_TAG=v$VERSION
git tag -a -m "tagging $GIT_TAG" $GIT_TAG
git push -u origin $GIT_TAG
pod spec lint quantumgraph.podspec
pod trunk push quantumgraph.podspec
'''
      }
    }
  }
}
