# Studentų pažymių valdymo programa 

# # Naudojimosi instrukcija

Programa veikia meniu principu ir leidžia valdyti studentų pažymius.

## Paleidimas

- Linux/MacOS: `./studentai`  
- Windows: `studentai.exe`

## Pagrindinis meniu

Pasirinkite veiksmą:

1. **Pridėti studentą rankiniu būdu**  
   - Įveskite vardą, pavardę, namų darbų ir egzamino pažymius (arba generuokite atsitiktinius).

2. **Nuskaityti studentus iš failo**  
   - Failas turi turėti antraštę: `Vardas Pavarde ND1 ND2 ... Egzaminas`.

3. **Rodyti studentų rezultatus**  
   - Pasirinkite galutinio balo skaičiavimo metodą: Vidurkis / Mediana / Abu.  
   - Rezultatai išsaugomi `rezultatai.txt`.  
   - Galima skirstyti studentus į:  
     - **Kietiakiai** (≥5) – `kietiakiai.txt`  
     - **Vargsiukai** (<5) – `vargsiukai.txt`

4. **Baigti programą**  

5. **Generuoti studentų failus (1k–10 mln)**  
   - Sukuria atsitiktinius studentų duomenų failus testavimui.

6. **Testuoti konteinerius (vector vs list)**  
   - Atliekami našumo testai nuskaitymui, rūšiavimui ir įrašymui.

7. **Automatinis testavimas su visais failais**  
   - Paleidžia visus testus automatiškai dideliems failams.

**Jūsų pasirinkimas yra:**



## v.01

Ši programa leidžia valdyti studentų pažymius, skaičiuoti galutinius balus ir išsaugoti rezultatus į failą. Programa suteikia galimybę studentus įvesti rankiniu būdu arba nuskaityti iš failo, generuoti atsitiktinius pažymius, ir skaičiuoti galutinį rezultatą naudojant vidurkį arba medianą.

---

## Funkcionalumas

1. **Studentų įvedimas rankiniu būdu**
   - Įvedamas vardas ir pavardė.
   - Galima įvesti namų darbų pažymius rankiniu būdu arba sugeneruoti atsitiktinius.
   - Egzamino pažymį galima įvesti rankiniu būdu arba sugeneruoti atsitiktinį.
   - Galutinis balas skaičiuojamas pagal vidurkį ir medianą:
     - `Galutinis (Vid.) = 0.4 * namų darbų vidurkis + 0.6 * egzamino pažymys`
     - `Galutinis (Med.) = 0.4 * namų darbų mediana + 0.6 * egzamino pažymys`

2. **Studentų nuskaitymas iš failo**
   - Failas turi būti tekstinis, su pirmąja eilute kaip header, pvz.:
     ```
     Vardas Pavarde ND1 ND2 ND3 ... Egzaminas
     ```
   - Programa perskaito studentus, patikrina, ar įvesti bent du pažymiai (namų darbai + egzaminas).

3. **Rezultatų atvaizdavimas ir išsaugojimas**
   - Rezultatai gali būti skaičiuojami pagal:
     - Vidurkį
     - Medianą
     - Abu (vidurkis ir mediana)
   - Rezultatai išsaugomi faile `rezultatai.txt`.

4. **Programa veikia meniu principu**
   - Galimi veiksmai:
     1. Pridėti studentą rankiniu būdu
     2. Nuskaityti studentus iš failo
     3. Rodyti studentų rezultatus
     4. Baigti programą
## Rezultatai

Programa skaičiuoja ir išsaugo studentų galutinius balus faile `rezultatai.txt`. Galutinis balas gali būti apskaičiuotas naudojant:

1. **Vidurkį (Galutinis (Vid.))**  
   - Skaičiuojamas taip:
     ```
     Galutinis (Vid.) = 0.4 * namų darbų vidurkis + 0.6 * egzamino pažymys
     ```
   - Šis metodas pabrėžia egzamino reikšmę (60% galutinio balo) ir naudoja visų namų darbų vidurkį kaip 40% galutinio balo dalį.
   - Tinka, kai norima, kad visų pažymių suma būtų atspindima vienu vidurkiu.

2. **Medianą (Galutinis (Med.))**  
   - Skaičiuojama taip:
     ```
     Galutinis (Med.) = 0.4 * namų darbų mediana + 0.6 * egzamino pažymys
     ```
   - Naudojama namų darbų mediana vietoje vidurkio, todėl vienas itin žemas arba aukštas pažymys mažiau įtakoja galutinį rezultatą.
   - Šis metodas suteikia stabilesnį galutinį balą, kai namų darbų pažymiai yra nevienodi.

3. **Abi (Vidurkis ir Mediana)**  
   - Programa gali išsaugoti tiek `Galutinis (Vid.)`, tiek `Galutinis (Med.)` stulpelius.
   - Tai leidžia palyginti, kaip skirtingi skaičiavimo metodai veikia studentų galutinius rezultatus.

**Pastaba:**  
- Visi rezultatai yra suformatuoti su dviem skaitmenimis po kablelio.
- Studentai rūšiuojami pagal vardą, kad rezultatai būtų tvarkingi ir lengvai skaitomi.
- Rezultatai išsaugomi faile `rezultatai.txt` tame pačiame kataloge, kuriame paleista programa.

# Studentų pažymių valdymo programa – Versija v.02

Ši dokumentacija tęsia ankstesnės versijos (v.01) aprašymą ir aptaria naujoves bei patobulinimus, įdiegtus versijoje Nr. 2.

---

## Naujos funkcijos ir patobulinimai v.02

1. **Studentų rūšiavimas pagal vardą**
   - Visi studentai dabar rūšiuojami pagal vardą prieš išvedant rezultatus.
   - Tai pagerina rezultatų tvarkingumą ir palengvina peržiūrą didesnėse grupėse.

2. **Galutinių balų pasirinkimas**
   - Vartotojas gali pasirinkti, kaip skaičiuoti galutinį balą:
     - Vidurkis (`Galutinis (Vid.)`)
     - Mediana (`Galutinis (Med.)`)
     - Abu variantai vienu metu
   - Šis patobulinimas suteikia daugiau lankstumo vertinant studentus.

3. **Studentų skirstymas į kategorijas**
   - Įdiegta funkcija automatiškai skirstyti studentus į dvi kategorijas:
     - **Kietiakiai** – galutinis balas ≥ 5
     - **Vargsiukai** – galutinis balas < 5
   - Rezultatai išsaugomi atskiruose failuose:
     - `kietiakiai.txt`
     - `vargsiukai.txt`

4. **Failų generavimas**
   - Pridėta galimybė generuoti studentų failus su atsitiktiniais duomenimis dideliam kiekiui studentų (nuo 1 tūkst. iki 10 mln.).
   - Naudinga testuojant programą su dideliais duomenų rinkiniais.

5. **Laikmatio matavimas**
   - Matuojamas laiką, reikalingą:
     - studentų rūšiavimui
     - rezultatų išvedimui į failą
     - skirstymui į kietiakiai/vargsiukai
   - Tai leidžia stebėti operacijų efektyvumą didelėse grupėse.

6. **Modulinė struktūra**
   - Programa padalinta į atskirus modulius:
     - `main.cpp` – pagrindinis meniu
     - `funkcijos.cpp/h` – studentų įvedimas, skaičiavimai, rezultatų spausdinimas
     - `duomenys.cpp/h` – failų nuskaitymas ir generavimas
     - `studentas.h` – studento struktūra
     - `laikmatis.h` – operacijų laiko matavimas

---

## Rezultatų aptarimas v.02

- **Galutinis balas pagal vidurkį:** naudoja visų namų darbų vidurkį; egzamino reikšmė – 60%.
- **Galutinis balas pagal medianą:** atsparus itin žemiems ar aukštiems pažymiams; egzamino reikšmė – 60%.
- **Skirstymas į kategorijas:** leidžia greitai identifikuoti stipriausius ir silpniausius studentus.
- **Išsaugomi failai:**
  - `rezultatai.txt` – visi studentai su galutiniu balu.
  - `kietiakiai.txt` – studentai su galutiniu balu ≥ 5.
  - `vargsiukai.txt` – studentai su galutiniu balu < 5.
- **Papildomas efektyvumo matavimas:** leidžia stebėti programos našumą dideliuose duomenų rinkiniuose.

---

## Pastabos

- Egzamino ir namų darbų pažymiai turi būti tarp 1 ir 10.
- Atsitiktinių pažymių generavimui naudojamas `rand()` su `srand(time(nullptr))`.
- Versija 0.02 išlaiko visą ankstesnės versijos funkcionalumą, bet prideda patogesnį rezultatų valdymą, rūšiavimą ir efektyvumo matavimą.






# Programos Testavimo Rezultatai v0.3 ir v1.0 (žemiau)

Šioje projekto dalyje atliekamas dviejų C++ konteinerių našumo testavimas, skirtas studentų duomenų nuskaitymui, rūšiavimui ir įrašymui.  
Šiame dokumente pateikiami išsamūs programos testavimo rezultatai, įskaitant dviejų konteinerių našumo matavimus pagal skirtingo dydžio failus.

**Testavimo data:** 2025–10–15

---

## Sistemos Parametrai

| Komponentas | Aprašymas |
|--------------|-----------|
| **Procesorius (CPU)** | AMD Ryzen 5 3550H with Radeon Vega Mobile Gfx, 2.10 GHz |
| **RAM** | 8 GB (naudojama ~5,88 GB) |
| **Grafika** | 6 GB, Radeon Vega Mobile Gfx |
| **Atmintis (HDD/SSD)** | 477 GB (SSD) |
| **Operacinė sistema (OS)** | Windows 11, 64-bit |

---

## Testavimo Metodika

Testuojami du C++ standartiniai konteineriai:  
- `std::vector`  
- `std::list`

Matavimai atliekami trimis pagrindinėmis operacijomis:
1. **Nuskaitymas** – duomenų nuskaitymas iš failo į konteinerį.  
2. **Rūšiavimas** – vargšiukai/kietiakiai skirstymas konteineryje.  
3. **Įrašymas** – duomenų įrašymas atgal į failą.  

Laikas matuojamas **sekundėmis** su tikslumu iki šešių skaičių po kablelio.

---

## Testavimo Rezultatai

| Failas | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Įrašymas (s) | Visas testas (s) |
|----------------------|-------------|----------------|---------------|----------------|----------------|
| studentai_1000.txt | std::vector | 0.0056859 | 0.000215 | 0.002819 | 0.011070 |
| studentai_1000.txt | std::list | 0.006416 | 0.000157 | 0.014394 | 0.022621 |
| studentai_10000.txt | std::vector | 0.042181 | 0.002711 | 0.016948 | 0.066189 |
| studentai_10000.txt | std::list | 0.043124 | 0.002033 | 0.016385 | 0.064150 |
| studentai_100000.txt | std::vector | 0.440618 | 0.026316 | 0.133719 | 0.604092 |
| studentai_100000.txt | std::list | 0.426942 | 0.020604 | 0.140861 | 0.592571 |
| studentai_1000000.txt | std::vector | 4.40848 | 0.271929 | 1.274328 | 5.957573 |
| studentai_1000000.txt | std::list | 4.367253 | 0.209767 | 1.425252 | 6.005412 |
| studentai_10000000.txt | std::vector | 44.783089 | 5.682959 | 13.204492 | 63.676864 |
| studentai_10000000.txt | std::list | 43.502372 | 2.101811 | 14.136841 | 59.744353 |

---

## Išvados

### 1. Maži failai (1000–10 000 įrašų)
1.1 `std::vector` šiek tiek greitesnis įrašant duomenis su 1000, taip ir nuskaitant failą, o `std::list` greitesnis rūšiuojant. Bendras laikas greitesnis su vektoriumi.  
1.2 `std::list` įrašymas, rūšiavimas yra šiek tiek greitesnis, tačiau nuskaitymas užtrunka ilgiau. Bendras laikas labai panašus, tačiau `std::list` greitesnis. (10 000)

### 2. Vidutinio dydžio failai (100 000–1 000 000 įrašų)
2.1 `std::list` (100 000) pranašesnis nuskaityme ir skirstyme, o `std::vector` – įrašyme.  
2.2 Bendras laikas rodo, kad skirtumas tarp `std::vector` ir `std::list` mažėja – `std::list` pranašesnis vos 0.1 sek.  
2.3 `std::vector` (1 000 000) lėtesnis už `std::list` tiek nuskaityme, skirstyme, bet greitesnis įrašyme.  
2.4 Bendrame laike `std::vector` laimi 0,05 sek.

### 3. Dideli failai (10 000 000 įrašų)
3.1 `std::vector` įrašymo laikas yra šiek tiek trumpesnis nei `std::list`, 1,1 sek.  
3.2 Abu konteineriai užtrunka daug laiko, tačiau `std::list` šiek tiek greitesnis bendrame rezultate, daugiausia dėl efektyvesnio rūšiavimo.

---

## Bendros Išvados

- Mažuose duomenų kiekiuose (iki 10 000 įrašų) reikšmingo skirtumo tarp konteinerių beveik nėra.  
- Vidutinio dydžio failuose (100 000–1 000 000 įrašų) našumo skirtumas tarp konteinerių pakankamai mažas.  
- Labai dideliuose duomenų kiekiuose (10 000 000 įrašų) skirtumai išryškėja.

---
# v.1.0
# Testų rezultatai: vector vs list


# Studentų konteinerių testavimas

Šioje projekto dalyje testuojamas **std::vector** ir **std::list** konteinerių našumas skirtingais atvejais: nuskaitymas, skirstymas ir įrašymas į failus.  
Taip pat atliktas papildomas testas su **std::vector**, naudojant **STL algoritmus**.

---

## Skirstymo strategijos

1. **Dvi kopijos** – sukuriami atskiri konteineriai *kietiakiams* ir *vargšiukams*.  
2. **Viena kopija su trynimu** – duomenys skirstomi vietoje, ištrinant nereikalingus.  
3. **Automatinis pasirinkimas** – parenkama greičiausia strategija pagal konteinerį.

---


| Failas | Strategija | Konteineris | Nuskaitymas (s) | Skirstymas (s) | Įrašymas (s) | Visas testas (s) | Studentai (baitai) | Kietiakiai (baitai) | Vargsiukai (baitai) |
|--------|-----------|-------------|----------------|----------------|---------------|-----------------|-------------------|-------------------|-------------------|
| studentai_1000.txt | 1 | vector | 0.011388 | 0.000624 | 0.011908 | 6.587381 | 104000 | 61984 | 42016 |
| studentai_1000.txt | 1 | list   | 0.009837 | 0.000390 | 0.004834 | 4.265823 | 120000 | 71520 | 48480 |
| studentai_1000.txt | 2 | vector | 0.007091 | 0.004588 | 0.003635 | 2.218336 | 61984 | 61984 | 42016 |
| studentai_1000.txt | 2 | list   | 0.008835 | 0.000318 | 0.006600 | 2.499706 | 71520 | 71520 | 48480 |
| studentai_1000.txt | 3 | vector | 0.007307 | 0.000251 | 0.004978 | 3.867256 | 104000 | 61984 | 42016 |
| studentai_1000.txt | 3 | list   | 0.010077 | 0.000502 | 0.004829 | 3.359666 | 71520 | 71520 | 48480 |
| studentai_10000.txt | 1 | vector | 0.103659 | 0.002038 | 0.024930 | 5.170371 | 1040000 | 614952 | 425048 |
| studentai_10000.txt | 1 | list   | 0.068396 | 0.003069 | 0.024734 | 3.392315 | 1200000 | 709560 | 490440 |
| studentai_10000.txt | 2 | vector | 0.064200 | 0.365824 | 0.032874 | 1.867561 | 614952 | 614952 | 425048 |
| studentai_10000.txt | 2 | list   | 0.072235 | 0.005389 | 0.032226 | 2.004752 | 709560 | 709560 | 490440 |
| studentai_10000.txt | 3 | vector | 0.063341 | 0.001482 | 0.022831 | 2.454926 | 1040000 | 614952 | 425048 |
| studentai_10000.txt | 3 | list   | 0.067361 | 0.005128 | 0.026153 | 1.869845 | 709560 | 709560 | 490440 |
| studentai_100000.txt | 1 | vector | 0.678737 | 0.013575 | 0.223477 | 4.181027 | 10400000 | 6082440 | 4317560 |
| studentai_100000.txt | 1 | list   | 0.648155 | 0.034280 | 0.246839 | 2.509687 | 12000000 | 7018200 | 4981800 |
| studentai_100000.txt | 2 | vector | 0.700131 | 43.801200 | 0.221867 | 46.298131 | 6082440 | 6082440 | 4317560 |
| studentai_100000.txt | 2 | list   | 0.629234 | 0.046543 | 0.273114 | 61.246084 | 7018200 | 7018200 | 4981800 |
| studentai_100000.txt | 3 | vector | 0.672563 | 0.013891 | 0.206427 | 2.306455 | 10400000 | 6082440 | 4317560 |
| studentai_100000.txt | 3 | list   | 0.648415 | 0.046395 | 0.220283 | 4.507188 | 7018200 | 7018200 | 4981800 |
| studentai_1000000.txt | 1 | vector | 7.188728 | 0.152040 | 2.279783 | 14.682385 | 104000000 | 60947848 | 43052152 |
| studentai_1000000.txt | 1 | list   | 7.352400 | 0.349458 | 2.243658 | 13.865441 | 120000000 | 70324440 | 49675560 |
| studentai_1000000.txt | 2 | vector | 7.081233 | 63.578412 | 2.325890 | 74.991123 | 60947848 | 60947848 | 43052152 |
| studentai_1000000.txt | 2 | list   | 6.982732 | 0.698352 | 2.356187 | 11.218531 | 70324440 | 70324440 | 49675560 |
| studentai_1000000.txt | 3 | vector | 6.993810 | 0.169437 | 2.291211 | 11.284984 | 104000000 | 60947848 | 43052152 |
| studentai_1000000.txt | 3 | list   | 6.924288 | 0.536978 | 2.304375 | 11.460528 | 70324440 | 70324440 | 49675560 |
| studentai_10000000.txt | 1 | vector | 69.409401 | 3.586494 | 23.406183 | 101.032615 | 1040000000 | 610196392 | 429803608 |
| studentai_10000000.txt | 1 | list   | 69.114784 | 3.592124 | 24.094034 | 100.384979 | 1200000000 | 704072760 | 495927240 |
| studentai_10000000.txt | 2 | vector | 69.271904 | 540.332457 | 23.684832 | 634.021341 | 610196392 | 610196392 | 429803608 |
| studentai_10000000.txt | 2 | list   | 69.072383 | 4.561772 | 24.115682 | 101.181837 | 704072760 | 704072760 | 495927240 |
| studentai_10000000.txt | 3 | vector | 69.492027 | 3.603214 | 23.531784 | 101.105241 | 1040000000 | 610196392 | 429803608 |
| studentai_10000000.txt | 3 | list   | 69.113822 | 4.561882 | 24.062441 | 100.414295 | 1200000000 | 704072760 | 495927240 |


# Studentų konteinerių testavimas (std::vector (pridėtas ir std::list, nors parametrai nekeisti) su STL

Šiame projekto etape testuojamas `std::vector` konteineris studentų duomenų nuskaitymui, skirstymui ir įrašymui į failus. Testai atliekami su skirtingais failų dydžiais ir trimis skirstymo strategijomis:

Pagal vidurkį
---
| Failas          | Konteineris | Studentų kiekis | Strategija 1 (s) | Strategija 2 (s) | Strategija 3 greitesnė (s) | Nuskaitymas (s) | Įrašymas (s) | Viso testas (s) |
| --------------- | ----------- | --------------- | ---------------- | ---------------- | -------------------------- | --------------- | ------------ | --------------- |
| studentai_1k    | std::vector | 1 000           | 0.000242         | 0.000379         | 0.000211                   | 0.015232        | 0.003362     | 12.548          |
| studentai_1k    | std::list   | 1 000           | 0.000312         | 0.000483         | 0.000295                   | 0.008451        | 0.004584     | 5.247           |
| studentai_10k   | std::vector | 10 000          | 0.00235          | 0.00312          | 0.00221                    | 0.072           | 0.011        | 14.7            |
| studentai_10k   | std::list   | 10 000          | 0.00312          | 0.00385          | 0.00305                    | 0.059           | 0.013        | 8.8             |
| studentai_100k  | std::vector | 100 000         | 0.0238           | 0.031            | 0.0215                     | 0.71            | 0.12         | 19.5            |
| studentai_100k  | std::list   | 100 000         | 0.0314           | 0.038            | 0.0296                     | 0.59            | 0.13         | 12.2            |
| studentai_1mln  | std::vector | 1 000 000       | 0.247            | 0.316            | 0.239                      | 6.85            | 0.96         | 26.4            |
| studentai_1mln  | std::list   | 1 000 000       | 0.317            | 0.384            | 0.305                      | 5.24            | 1.05         | 19.8            |
| studentai_10mln | std::vector | 10 000 000      | 2.61             | 3.25             | 2.53                       | 68.1            | 9.8          | 118.5           |
| studentai_10mln | std::list   | 10 000 000      | 3.25             | 3.88             | 3.15                       | 52.5            | 10.9         | 87.4            |

Pagal medianą

| Failas          | Konteineris | Studentų kiekis | Strategija 1 (s) | Strategija 2 (s) | Strategija 3 greitesnė (s) | Nuskaitymas (s) | Įrašymas (s) | Viso testas (s) |
| --------------- | ----------- | --------------- | ---------------- | ---------------- | -------------------------- | --------------- | ------------ | --------------- |
| studentai_1k    | std::vector | 1 000           | 0.00027          | 0.00041          | 0.00023                    | 0.0154          | 0.0035       | 12.7            |
| studentai_1k    | std::list   | 1 000           | 0.00036          | 0.00050          | 0.00034                    | 0.0086          | 0.0046       | 5.29            |
| studentai_10k   | std::vector | 10 000          | 0.00248          | 0.00320          | 0.00235                    | 0.073           | 0.011        | 14.9            |
| studentai_10k   | std::list   | 10 000          | 0.00328          | 0.00398          | 0.00315                    | 0.061           | 0.013        | 8.9             |
| studentai_100k  | std::vector | 100 000         | 0.0252           | 0.0325           | 0.0243                     | 0.72            | 0.12         | 19.7            |
| studentai_100k  | std::list   | 100 000         | 0.0336           | 0.0401           | 0.0321                     | 0.61            | 0.13         | 12.4            |
| studentai_1mln  | std::vector | 1 000 000       | 0.259            | 0.332            | 0.248                      | 6.91            | 0.97         | 26.8            |
| studentai_1mln  | std::list   | 1 000 000       | 0.334            | 0.398            | 0.320                      | 5.30            | 1.05         | 20.0            |
| studentai_10mln | std::vector | 10 000 000      | 2.73             | 3.41             | 2.61                       | 68.8            | 9.9          | 119.3           |
| studentai_10mln | std::list   | 10 000 000      | 3.41             | 4.08             | 3.25                       | 53.1            | 10.9         | 88.2            |


Atminties testavimas tiek pagal vidurkį, tiek pagal medianą

| Failas         | Konteineris | Balas    | Strategija | Bendras konteineris | Kietiakiai | Vargsiukai | Viso (apytiksliai) |
|----------------|------------|---------|------------|-------------------|------------|------------|-------------------|
| studentai_1k   | vector     | Vidurkis | 1          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | vector     | Vidurkis | 2          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | vector     | Vidurkis | 3          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | list       | Vidurkis | 1          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_1k   | list       | Vidurkis | 2          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_1k   | list       | Vidurkis | 3          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_1k   | vector     | Mediana  | 1          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | vector     | Mediana  | 2          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | vector     | Mediana  | 3          | 72 000            | 42 912     | 29 088     | 144 000           |
| studentai_1k   | list       | Mediana  | 1          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_1k   | list       | Mediana  | 2          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_1k   | list       | Mediana  | 3          | 80 000            | 47 680     | 32 320     | 160 000           |
| studentai_10k  | vector     | Vidurkis | 1          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | vector     | Vidurkis | 2          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | vector     | Vidurkis | 3          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | list       | Vidurkis | 1          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_10k  | list       | Vidurkis | 2          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_10k  | list       | Vidurkis | 3          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_10k  | vector     | Mediana  | 1          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | vector     | Mediana  | 2          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | vector     | Mediana  | 3          | 720 000           | 429 120    | 290 880    | 1 440 000         |
| studentai_10k  | list       | Mediana  | 1          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_10k  | list       | Mediana  | 2          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_10k  | list       | Mediana  | 3          | 800 000           | 476 800    | 323 200    | 1 600 000         |
| studentai_100k | vector     | Vidurkis | 1          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | vector     | Vidurkis | 2          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | vector     | Vidurkis | 3          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | list       | Vidurkis | 1          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_100k | list       | Vidurkis | 2          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_100k | list       | Vidurkis | 3          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_100k | vector     | Mediana  | 1          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | vector     | Mediana  | 2          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | vector     | Mediana  | 3          | 7 200 000         | 4 291 200  | 2 908 800  | 14 400 000        |
| studentai_100k | list       | Mediana  | 1          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_100k | list       | Mediana  | 2          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_100k | list       | Mediana  | 3          | 8 000 000         | 4 768 000  | 3 232 000  | 16 000 000        |
| studentai_1mln | vector     | Vidurkis | 1          | 72 000 000        | 42 912 000 | 29 088 000 | 144 000 000       |
| studentai_1mln | vector     | Vidurkis | 2          | 72 000 000        | 42 912 000 | 29 088 000 | 144 000 000       |
| studentai_1mln | vector     | Vidurkis | 3          | 72 000 000        | 42 912 000 | 29 088 000 | 144 000 000       |
| studentai_1mln | list       | Vidurkis | 1          | 80 000 000        | 47 680 000 | 32 320 000 | 160 000 000       |
| studentai_1mln | list       | Vidurkis | 2          | 80 000 000        | 47 680 000 | 32 320 000 | 160 000 000       |
| studentai_1mln | list       | Vidurkis | 3          | 80 000 000        | 47 680 000 | 32 320 000 | 160 000 000       |
| studentai_10mln| vector     | Vidurkis | 1          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| vector     | Vidurkis | 2          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| vector     | Vidurkis | 3          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| list       | Vidurkis | 1          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |
| studentai_10mln| list       | Vidurkis | 2          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |
| studentai_10mln| list       | Vidurkis | 3          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |
| studentai_10mln| vector     | Mediana  | 1          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| vector     | Mediana  | 2          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| vector     | Mediana  | 3          | 720 000 000       | 429 120 000| 290 880 000| 1 440 000 000     |
| studentai_10mln| list       | Mediana  | 1          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |
| studentai_10mln| list       | Mediana  | 2          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |
| studentai_10mln| list       | Mediana  | 3          | 800 000 000       | 476 800 000| 323 200 000| 1 600 000 000     |





 


 

## Testų rezultatai



## Vector su STL algoritmais

- **Strategija 1 (dvi kopijos)** – dažniausiai greičiausia.  
- **Strategija 2 (viena kopija su trynimu)** – efektyvi tik su mažais failais.  
- **Strategija 3 (automatinė)** – paprastai pasirenka skirtingas strategijas.  
- Atminties naudojimas auga proporcingai failo dydžiui.  
- Naudojant **STL algoritmus**, programa veikia greitai, bet sunaudoja šiek tiek daugiau atminties dėl laikinų kopijų.

---

## Bendros išvados
# Vector ir List palyginimas pagal strategijas

## Strategija 1 – Dvi kopijos (kietiakiai + vargšiukai)

- **Vector**: labai greitas ir stabilus, nes duomenys saugomi nuosekliai atmintyje.  
- **List**: šiek tiek lėtesnis dėl rodyklių ir išskaidytos atminties.  
- **Išvada:** ši strategija **labiausiai tinka vector**, ypač dideliems failams.

---

## Strategija 2 – Viena kopija su trynimu

- **Vector**: labai **lėtas**, nes kiekvieno elemento trynimas perstumia kitus (ypač kai duomenų daug).  
- **List**: **greitas**, nes elementų trynimas tik pakeičia rodykles, be papildomų kopijų.  
- **Išvada:** ši strategija tinkama tik **list** konteineriui.  
  Naudojant ją su **vector**, laikas stipriai išauga (iki šimtų sekundžių su dideliais failais).

---

## Strategija 3 – Automatinis pasirinkimas

- **Vector** automatiškai pasirenka **1 strategiją**, nes ji greičiausia jam.  
- **List** pasirenka **2 strategiją**, kuri efektyviausia jam.  
- **Išvada:** ši strategija užtikrina optimalų pasirinkimą pagal konteinerį.

---

## Bendros išvados

- **Vector** – geriausias pasirinkimas su **1 strategija** ir dideliais duomenimis.  
- **List** – geriausias su **2 strategija**, kai reikia daug trynimų arba duomenų mažiau.  
- **Strategija 2** yra **labai neefektyvi vector konteineriui**, nes trynimai užtrunka ilgai.  
- **Automatinis režimas (3)** išsprendžia šią problemą, pasirinkdamas greitesnį metodą.

---
# Studentų pažymių valdymo programa – Įdiegimas

## Reikalavimai

- **CMake** ≥ 3.10  
- Kompiliatorius: Visual Studio (Windows), GCC / Clang (Linux / Mac)  
- Projekto failai: `main.cpp`, `funkcijos.cpp/h`, `duomenys.cpp/h`, `studentas.h`, `laikmatis.h`  
- `CMakeLists.txt` projekte

---

## Projekto įdiegimas

1. Atidarykite terminalą ir eikite į projekto katalogą:
```bash
cd /path/to/project
2. Sukurkite katalogą build ir pereikite į jį:
mkdir build
cd build
3. Generuokite projektą pagal savo OS/kompiliatorių:
Windows/Visual Studio
cmake .. -G "Visual Studio 17 2022"
Sugeneruotas .sln failas leis atidaryti projektą Visual Studio.
Projekto kompiliavimas ir paleidimas atliekamas tiesiai iš Visual Studio.
Linux / Mac
cmake ..
make
Sukuriamas vykdomasis failas studentai.

Paleidimas
Windows (Visual Studio): atidarykite .sln ir paleiskite projektą.

Linux / Mac: terminale:
./studentai



 

