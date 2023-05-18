## Úkoly 

 

### Vyrobit

- stop tlačítko s indikační LED
- start tlačítko 
- ohrádka na mobil, kde se vypisují data 
- nahoře svislý panel s reklamou Sokolské 
- přidělat ruku 
- stojan pro magnetometr + majáček pro RA Beg. 


## Vize 

pokud možno na start co nejblíže čáře a co nejkratší oblouky v meandru 
zprovoznit magnetometr 


proměnné :
- o kolik je vyvýšená zadní část hřiště 
- kde je která barva 



## Algoritmus 

- na přední liště jsou dva dotykové senzory + dva infrasenzory na přibližnou vzdálenost 
- při každém vyložení kostky  robot přibrzdí podle infra, vyloží kostku, zvedne ruku a  na dotek se srovná na kolmo 
- projet eSko pozadu (přední lišta se senzory + bočnice je chráněná)
- sklopit ruku a použít ji jako radlici mezi kostkami (tam i zpět)
- na konci zóny kostek se otoč vpravo, tím se shrnou kostky na stranu a mám čistý prostor vpravo u zdi 
- měřím vzdálenosti ke zdi ultrazvukem + magnetometrem 

včas ukončit činnost a vrátit se 




#### Další 

 mít definované pole, kde zastavím a počkám na konec  -> podle soupeře, výchozí je A3
 pro jistotu také časovač na 5 minuty (bez pár sekund), který vypne motory a spadne do Kubovy pasti 


#### Poznámky

možnost z PID funkce nebo  z PWM funkce vyskočit (proměnná, kterou to bude kontrolovat ano/ne ) při splnění zadaného parametru / zadané hodnoty PWM 
možnost z PID funkce nebo  z PWM funkce něco udělat  při splnění zadaného parametru / zadané hodnoty PWM  (během otočky měřím v konkrétní pozici ultrazvukem vzdálenost)




## Postup 

* QRD číst 
* IR senzory - mají v sobě komparátor -> číst přes digitalRead(); na kterémkoli pinu 
* ultrazvuk? 
* kalibrace senzorů 
* zatočit o 90 stupňů
* jedu (skoro) rovně
* funkce, která vrací kde pod lištou přední/zadní je čára (pod kterým senzorem, číslo od -50 do 50, druhý parametr - indikace křižovatek)
* srovnání se na čáře 
* uvnitř procedury na rychlost postupné zrychlování a zpomalování ? 


## Poznámky všeobecné

výška není omezená v Praze ani v Bratislavě 
v Bratislavě se jezdí 3 minuty 

u serva je nějaká chyba, která způsobuje, že nestačí zapnout attach, ale je potřeba poslat do serva první pokyn, aby začal attach posílat do serva signál - ověřit

ověřit kód pro blikání LED přes expandér 





