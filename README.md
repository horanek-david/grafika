# Horanek Dávid - Számítógép grafika beadandó feladat

* **_Feladat leírása:_** A feladatban egy kis város található házakkal, benne bútorokkal valamint egy irányítható autó az utcán.
### Objektumok:
Összesen 18db modellünk van.
* Két _szék_ modell, az egyik az asztalhoz tartozó szék míg a másik egy hintaszék a szoba sarkában.
* Egy _asztal_ modell ami a szoba közepén helyezkedik el.
* Egy _kisszekrény_ modell, a bejárattal szemben.
* Egy _barikád modell_, segít abban hogy körbezárjuk a kis várost vele.
* Egy _kerítés_ modell, a házak köré.
* Három _ház_ modell, egy a főház, egy a szomszédos házakhoz és egy nagyobb a fő házzal szemben.
* Egy _fa_ ami két modellből tevődik össze, a levelekből és a törzsből.
* Egy _autó_ ami 5 modellre lett szedve. Egy első kerekekre valamint hátsó kerekekre, lámpákra, üvegekre és az autó testére.
* Egy _utcai_ lámpa ami az üveg és pózna modellből áll.

A földhöz és az utakhoz glVertex3f-szel rajzolom ki a lapokat és rakom rá a fű valamint a beton textúrákat. A legtöbb modellnek saját textúrája van de például a bútorok ugyanazon a textúrán osztoznak.

## Funkciók:
* Kamera mozgatása a **'W-A-S-D'** és **'Q-E'** billenytűkkel.
* Autó mozgatása a **'nyilak'**-kal valamint a reflektor fel- és lekapcsolása a **'SPACE'**-szel. Az autó mozgásával a kerekek megfelelő irányba forognak, amikor oldalirányba kanyarodunk a kerek a megfelelő szögben kifordulnak és ha felengedjük a **jobbra-balra** nyilat akkor a kerekek egyenesbe állnak. Az autó üvegein az átlátszóság belett állítva.
* A nappal és éjszaka bemutatására a nap fényerejének le- és felvétele a **'+'** és **'-'** billentyűkkel. Ehhez tartoznak az utcai lámpák fényei amik automatikusan fel vagy lekapcsolnak, hogyha levesszük a nap fényerejét egy adott százalék alá.
* A hintaszék magától mozog az idő függvényével.
* A program rendelkezik súgóval amit az **'F1'** billenytűvel hozhatunk elő.
* A ködöt az **'F2'** billentyű segítségével tudjuk ki- és bekapcsolni.

### Mappa a modellekhez és textúrákhoz: https://1drv.ms/u/s!AocACvgp0az3jKhbi-YVpOF_Bwuerg?e=liiQJx
