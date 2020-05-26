#!/usr/bin/env groovy

pipeline {
  agent {
    label "mobile-mac-mini"
  }

  stages {
    stage('build') {
      steps {
        step([$class: 'WsCleanup'])
        checkout scm
        script {
          AGENT_WORKSPACE = WORKSPACE
        }
        // Make sure script runs in the directory of "checkout scm"
        dir(AGENT_WORKSPACE) {
          sh "publish.sh"
        }
      }
    }
  }
}
