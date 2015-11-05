# language: en

Feature: Read state of switch
  As a webui
  I want to read the state of the switch
  In order to show it to the user

Scenario Outline: read state of switch
  Given the switch is <switch state>

  When I request data

  Then I expect an xml with a node <node> with an attribute <attribute>=<value>

Examples:
  | switch state | node   | attribute | value |
  |       on     | switch | state     |  "on" |
  |      off     | switch | state     | "off" |
