# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Read switch information
  As a webui
  I want to read information about the switch
  In order to show it to the user

Scenario Outline: read state of switch
  Given the switch is <switch>

  When I request data

  Then I expect the following line in the http response:
    """
    <switch state="<switch>"/>
    """

  Examples:
    | switch |
    |     on |
    |    off |
