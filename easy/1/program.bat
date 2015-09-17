@echo OFF

SET /P name= "Enter your name:  "

:ASK_AGE
SET /P age= "Enter your age:    "
SET /A validateAge= age

IF %validateAge% LEQ 0 (
    ECHO Please Enter a valid age
    GOTO :ASK_AGE
)

SET /P redditName= "Enter your Reddit username:    "

ECHO Your name is %name%, you are %age% year(s) old, and your username is %redditName
PAUSE
