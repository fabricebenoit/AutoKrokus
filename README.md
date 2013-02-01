AutoKrokus
==========

_Arduino based RC f/stop Enlarger Timer_

See [AutoKrokus HomePage](http://fabricator.blog.com/2013/01/23/autokrokus/) (French) or 
[AutoKrokus GitHub Page](http://fabricebenoit.github.com/AutoKrokus/) (English) for more details about this project.

Features
--------

- **Remote Controled**: A 433MHz Rx/Tx kit is used.
- **Test Stripes Mode**: Given a base exposure time and a f/stop range, calculates stripes exposures times and expose them, notify the user when he has to move the mask to next stripe.
- **Exposure Mode**: Exposition can be paused and continued.
- **Chemistry Timer**: Notify the user when it's time to go to the next processing step.
- **Red Light Handler** Set red light low during paper placement and exposure, set it gradually higher during processing.

Hardware
--------

You will need two Arduinos to build this project.
I choosed an Arduino UNO for the enlarger and an Arduino Mini for the remote controller.

Test sketches are 

- **KrokusRemoteTest** for the remote controller Hardware Test
- **KrokusRemoteTestRx** to log the data transmitted by the controller during the test
