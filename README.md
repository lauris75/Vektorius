# std::vector atitinkantis headeris (nepilnas)

## Programos tikslas

Sukurti std::vector visa funkcionaluma atitinkanti header faila.

### Naudojimasis programa

Includinti i jusu norima projecta, kaip paprasta #include.

## Rezultatai

Puch_back (ir resize kartu) funkciju greiciu palyginimas tarp Vector ir std::vector:

- Irasu kiekis - 10000
- Irasant duomenis i std::vector prireike 1000000 nanosekundziu
- Irasant duomenis i Vector prireike 0 nanosekundziu
- Irasu kiekis - 100000
- Irasant duomenis i std::vector prireike 2990000 nanosekundziu
- Irasant duomenis i Vector prireike 4986000 nanosekundziu
- Irasu kiekis - 1000000
- Irasant duomenis i std::vector prireike 34908000 nanosekundziu
- Irasant duomenis i Vector prireike 15957000 nanosekundziu
- Irasu kiekis - 10000000
- Irasant duomenis i std::vector prireike 258308000 nanosekundziu
- Irasant duomenis i Vector prireike 137632000 nanosekundziu
- Irasu kiekis - 100000000
- Irasant duomenis i std::vector prireike 2089414000 nanosekundziu
- Irasant duomenis i Vector prireike 1047198000 nanosekundziu

## Versijos

### [v1.0](https://github.com/lauris75/Vektorius/releases/tag/VEC1.0v) - (2018-03-25)
**Pridėta**
- std::vector atitinkantis headeris (neisbaigtas)
- push_back funkcijos spartai lyginti naudotas kodas (.cpp faile)
