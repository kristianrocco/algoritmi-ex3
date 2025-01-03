# algoritmi-ex3
Questo progetto nasce con l'obiettivo di implementare una libreria generica per la gestione di una tavola hash con concatenamento. La struttura è stata progettata per supportare coppie chiave-valore di tipi generici, offrendo flessibilità nell'uso. Il progetto richiedeva di creare una tavola hash con funzionalità chiave come inserimento, ricerca, rimozione e gestione dinamica delle chiavi e dei valori. Doveva inoltre essere garantita la possibilità di personalizzare la funzione hash e il criterio di confronto per adattarsi a diversi tipi di dati.

La libreria offre un insieme di funzionalità ben definite:
hash_table_create: inizializza una tavola hash con una funzione hash e una funzione di confronto personalizzate.
hash_table_free: libera la memoria associata alla tavola hash.

Operazioni principali:
hash_table_put: inserisce una coppia chiave-valore.
hash_table_get: recupera il valore associato a una chiave.
hash_table_remove: rimuove una chiave (e il valore associato).

Analisi e gestione:
hash_table_contains_key: verifica se una chiave è presente.
hash_table_size: restituisce il numero di elementi nella tavola.
hash_table_keyset: restituisce un array con tutte le chiavi

La tavola hash è stata realizzata utilizzando concatenamento per gestire le collisioni. Ogni bucket è una lista collegata, in cui i nodi memorizzano la chiave e il valore. L'approccio scelto garantisce flessibilità e permette di gestire tipi generici, con l'utente che fornisce funzioni personalizzate per il confronto e l’hashing delle chiavi.

Nonostante i benefici, abbiamo riscontrato alcune limitazioni:
La necessità di verificare manualmente ogni implementazione per evitare errori logici.
Iterazioni aggiuntive per migliorare la gestione dinamica della memoria e implementare correttamente tutte le funzionalità richieste.
