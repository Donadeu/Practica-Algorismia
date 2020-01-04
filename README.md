# LP-Pràctica Quizbot

Pràctica de Compiladors i Python de Llenguatges de Programació (FIB)

#### PRE-REQUISITS:
Per instal·lar el software executa la següent comanda al terminal:

pip install -r requirements.txt


#### CREACIÓ D'UNA ENQUESTA:
Per tal de crear una nova enquesta cal executar la següent comanda:
```
python3 cl/test.py
```

A continuació cal entrar les dades pel terminal mitjançant el mateix format que el fitxer d'entrada que pots trobar a:
- entrada (cl/entrada)

En canvi, si es vol, es poden entrar les dades de l'enquesta directament amb un fitxer executant la següent comanda:

```
python3 cl/test.py cl/entrada
```

Aquest script ens generarà un fitxer anomenat graf_"id de l'enquesta".p que contindrà el graf que utilitzarà l'script del bot.

A continuació copiem aquest fitxer al directori del bot per tal de que el pugui utilitzar amb la següent comanda:

```
cp -r cl/graf_E.p bot/
```
Suposant que la enquesta es digui "E".

Finalment per executar el bot és necessari crear-se un bot visitant el @BotFather a telegram.
Seguidament usar la comanda:
```
/newbot
```
Completar la informació demanada i desar en un fitxer token.txt el vostre acces token.
Aquest fitxer s'ha de trobar al mateix directori que l'script bot.py per tal de que el trobi.

Per tal d'executar el bot:

```
cd bot/
python3 bot.py
```
Esperar que es carregui i ja hi podeu interactuar!

Finalment, només tenir en compte que per poder fer els gràfics i els reports el bot es guarda les respostes a un fitxer
que es trobarà al mateix directori des d'on s'executi el bot, a més de les imatges generades dels gràfics.


####AUTORS

- Jordi Donadeu Casassas, amb correu jordi.donadeu@est.fib.upc.edu
