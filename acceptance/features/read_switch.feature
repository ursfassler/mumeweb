# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Read switch information
  As a webui
  I want to read information about the switch
  In order to show it to the user

Scenario Outline: read state of switch
  Given the switch count is 0
  And the switch is <switch>

  When I request data

  Then I expect the following line in the http response:
    """
    <switch state="<switch>" count="0"/>
    """

  Examples:
    | switch |
    |     on |
    |    off |

Scenario Outline: read switch count
  Given the switch is off
  And the switch count is <counter>

  When I request data

  Then I expect the following line in the http response:
    """
    <switch state="off" count="<counter>"/>
    """

  Examples:
    | counter |
    |       0 |
    |       1 |
    |      42 |
    |     111 |
    | 5405536 |
