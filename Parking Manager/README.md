    Aplicatia nu valideaza toate input-urile considerand ca sunt corecte
    Pretul pe ora si limitarile parcatii pot fi modificate in mainwindow.h

Repoository:
Constructor-ul apeleaza functia repoFromFile() astfel memorand toate vehiculele
Destructor-ul appeleaza functia repoToFile() astfel salveaza toate modificarile efectuate
    elems:
        o matrice de string-uri in care sunt stocate datele
    source:
        un string care contine numele fisierului care va fi folosit
    get_elem():
        returneaza elems
    repoFromFile():
        citeste fisierul .txt si adauga in memorie toate vehiculele
    repoToFile():
        rescrie in fisier fiecare  vehicul dupa cum sunt salvate in memorie
    add_elem():
        adauga un vehicul in memorie (folosit in repoFromFile())

Date:
Clasa creata pentru a usura scrierea si citirea din fisier
    <<:
    operatorul << a redefinit pentru a scrie usor in fisier

MainWindow:
Contine partea functionala si de design
    populate_table():
        adauga toate vehiculele in tabelul din aplicatie, oferindu-le un loc in functie de dimensiune si greutate sau ignorandu-le daca nu mai este loc pentru acea categorie
    update_profit():
        calculeaza profitul (in functie de pricePerH) si il afiseaza in aplicatie
    on_Update_clicked():
        updateaza vehiculul selectat cu valorile introduse in aplicatie. Doar data plecarii se poate modifica in caz de prelungire si greutatea
    check_vehicle_type():
        verifica ce tip de vehicul primeste si returneaza marimea lui (S, M sau L)