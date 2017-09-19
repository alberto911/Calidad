require 'watir'
browser = Watir::Browser.new :firefox

browser.goto 'http://blazedemo.com'
browser.select_list(name: 'fromPort').options[5].select
browser.select_list(name: 'toPort').options[3].select
browser.button(text: 'Find Flights').click

browser.buttons(text: 'Choose This Flight').last.click

browser.text_field(id: 'inputName').set('Alberto Pickering')
browser.text_field(id: 'address').set('Una calle 37')
browser.text_field(id: 'city').set('CDMX')
browser.text_field(id: 'state').set('CDMX')
browser.text_field(id: 'zipCode').set('11520')
browser.select_list(id: 'cardType').options[1].select
browser.text_field(id: 'creditCardNumber').set('12345678')
browser.text_field(id: 'creditCardMonth').set('03')
browser.text_field(id: 'creditCardYear').set('2020')
browser.text_field(id: 'nameOnCard').set('Alberto Pickering')
browser.checkbox(id: 'rememberMe').set
browser.button(text: 'Purchase Flight').click
