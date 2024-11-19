## desc:
I often go out to eat alone with my fiancé Chizuru, at one of those fancy restaurants. While eating, suddenly one of the employees who recognized me told me that his computer was doing something strange. According to him, it was probably one of the other employees who hated him, and he wanted to know more details regarding this matter. Even though I'm on a date right now huft :(
> https://drive.google.com/drive/folders/1q-92vT4j0fYbDC6aDDE-jx77gJ5PcfCv?usp=drive_link

## flag:
```SNI{c2_server_via_trello_8hs73b1k17sf}```

## poc
- Analyze the traffic
- We can see that on the http request, there is some kind of parameter that use for bash or shell command
- Analyze the bash command and scripting to recover the password.txt content
- Use the token and api key provided in get request to get list of the lists in the trello board  
- Get the content of Secret card which is pastebin link
- enter the password of pastebin link use password.txt content

## topic:
- PCAP
