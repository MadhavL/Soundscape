# Soundscape
Interactive “soundscape” - an installation that modulates sound based on physicality and bodily or even environmental movement.

I created an interactive “soundscape” - an installation that modulates sound based on physicality and bodily or even environmental movement.

The motivation behind this project is three-fold: 1) to create an interactive soundscape with sonically interesting sounds being modulated according to certain movements, 2) to demonstrate a tangible connection between physicality and sound to improve the audience’s understanding of how different sounds are synthesized and generated, and 3) to create an open-source code framework for taking in input from sensors on hardware and routing them to synthdefs so that other artists can plug-and-play with their own sensors and sounds for creative purposes.

So here’s the basic idea behind this sound installation: the inputs are various sensors that measure certain values relating to motion and movement. These sensors feed their values to a microcontroller (in this case an Arduino UNO). The microcontroller then applies some basic processing on these values to make them slightly more usable for the sound generation software before sending it via serial to the computer running the sound generation software (in this case, SuperCollider). Then, SuperCollider reads in the values from the microcontroller and uses those values for various purposes - changing frequencies, modulating amplitudes, panning, cutoffs, etc.

Read more [here](https://fifth-umbrella-77d.notion.site/Interactive-Soundscape-Madhav-Lavakare-bb65cb7edac84cedb85c54a27cfa0526)
