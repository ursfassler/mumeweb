# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Read state of switch
  As a webui
  I want to read the state of the switch
  In order to show it to the user

Scenario: read state of switch
  Given the switch is on

  When I request data

  Then I expect the http response:
    """
    Content-Type: text/xml

    <mume><switch state="on"/></mume>
    """
