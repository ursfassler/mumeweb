# Copyright 2015 Urs Fässler, www.bitzgi.ch
# SPDX-License-Identifier:	GPL-3.0+

# language: en

Feature: Write end positions of servo
  As a webui
  I want to write the end positions of the servo
  In order to calibrate the machine

Scenario Outline: write open position of the servo
  When I set the http request header "Content-Type" to "application/xml"
  And I set the http request content to:
    """
      <mume><openPositionMs value="<value>"/></mume>
    """
  And I request data

  Then I expect a D-Bus request setOpenPositionMs with the value <value>

  Examples:
    | value |
    |  0.01 |
    |   100 |
    | 0.012 |
    | 12.34 |
