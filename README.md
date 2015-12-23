GarageDoor
==========

My garage door project

You can found more information here : http://bidouillesfactory.fr/tag/porte-de-garage/

# Project IDE
I use Eclipse CDT with the plug-in "Arduino C++ IDE"
-> See https://marketplace.eclipse.org/content/arduino-c-ide

# Project structure

* **.project** the eclipse project description
* **.cproject** the eclipse C project description
* **.settings/** some eclipse variables
* **sd-card/** The content of the micro-SD card inserted into the Ethernet shield
* **libraries/** a copy of the arduino library that I use for my project
  * **Twitter/** a great Twitter Library. More informations here : http://arduino-tweet.appspot.com/
  * **Webduino/** A Arduino lib to turn it into a webserver. Available here : https://github.com/sirleech/Webduino
* **side-web-server/** Some files that I put on my own home web server to cache some images and libs (like jQuery)
* **src/** My sources files

# How to fill credentials

One file must be modified in order to put your own credentials : **sd-card/credent.txt**

Content :
```
AUTH_CREDENTIALS=AAAA
TWITTER_TOKEN=BBBB
```

You must replace AAAA by your login and password concatenated with a ':'.
For exemple if your credential are login:foo, pwd:bar then you have to convert this string : "foo:bar" in base 64.
You can found an online converter here : http://www.motobit.com/util/base64-decoder-encoder.asp

You must replace BBBB by your Twitter Token.
You can get a token to post a message using OAuth here : http://arduino-tweet.appspot.com/oauth/twitter/login

