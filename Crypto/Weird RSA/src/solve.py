from Crypto.Util.number import long_to_bytes

n =  110223867746640965637669407552200539300404951940768922626582126620277066812791667641777082687154314924063023851590405173123594044684465359525968546353220060077378235806055903644738787114955134145583027933486021793899403480011282191691500982373555555656504653560686754735448569923801597654019701001782484065071
e =  65537
c =  101650847822923866634342729608400565998505884084276942969417606985521641681029353145045350584846972739992534688286585744643195719775872682045707770452738645334803464930727255506592812075527569723183312927425192465942290775111371647005607833363470384342180049453831084341449156409625358355424770931826856361541

m = pow(c,e,n)
for i in range(100000):
    temp = m+n*i
    if b"SNI" in long_to_bytes(temp):
        print(long_to_bytes(temp))