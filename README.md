# QANALYTICS - Progetto di Programmazione ad Oggetti 2020 - UniPD

<p align="center">
  <img src="Screen+file/qanalyticslogo.png?raw=true" width="170">
</p>


## Informazioni

Il progetto consiste in un'applicazione utile ad analizzare e visualizzare statistiche ricavate dai profili social dei propri clienti.
Le informazioni vengono disposte in grafici popolati, concettualmente, tramite l’interfacciamento dell’applicazione ad un database o alle API dei social network; operazione che a fine esemplificativo è stata realizzata come una deserializzazione di un file JSON.

Dall’interfaccia grafica sono disponibili solamente statistiche relative agli account ma la logica del programma è predisposta anche alla gestione e visualizzazione dei singoli contenuti.


Per la realizzazione dei grafici l’applicazione sfrutta il modulo QCHARTS di Qt. 

## Ambiente di sviluppo
- IDE e Framework: Qt 5.9.5
- Compilatore: MinGW 5.3.0
- Moduli QT supplementari: QCharts
- Flags QMake:  QT += core gui charts

## Autori
- [Ayoub Maher](https://github.com/ayoubmaher)
- [Giacomo Sassaro](https://github.com/Panz99)
- [Gianpiero Tovo](https://github.com/gianpics)
