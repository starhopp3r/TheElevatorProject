/* A tune is entered in as a string. A note has two values a) tone b) duration
  There are 25 tones from middle C, 1 and 2 octaves above: They are C, c, H 
   Only sharps are accepted, so D#=Eb. Don't use E# and B# as they are invalid!
   |  |- |= The durations are: crochet / quaver / semiquaver     
  *  *  *   OR c / q / s, respectively. 
   So, Fq will play the F note above middle C for a quaver value.
   You may use quotes for separate lines of a song, to make your transcription 
   easier
*/
const char MusicBoxDancer[]=
"cqcqGqcqeqcqeqgqcq"
"Hqbqaqgqgqgq"
"gqfqdqBqGqBqdqGq"
"eqcqaqgqgcgqcq"
"cqGqcqeqcqeqgqcq"
"Hqbqaqgqgqcqcq" 
"gqGqdqBqGqBqdqBq"
"cqGqeqcqcqcq";

const char TurkishRondo[]=
"BsAsG#sAsccdscsBscsec"
"fsesd#sesbsasg#sasbsasg#sasHc"
"aqHqbqaqgqaqbqaq"
"gqaqbqaqgqf#qec"
"eqfqgqgqasgsfsesdc"
"eqfqgqgqasgsfsesdc"
"cqdqeqeqfsesdscsBc"
"cqdqeqeqfsesdscsBc"
"BsAsG#sAsccdscsBscsec"
"fsesd#sesbsasg#sasbsasg#sasHc"
"aqbqHqbqaqg#qaqeq"
"fqdqccBscsdsBsAqaq";

const char MinuetG[]=
"dcGqAqBqcqdcGcGceccqdqeqf#qgcGcGcccdqcqBqAqBccqBqAqGq"
"F#cGqAqBqGqBcAcAcdcGqAqBqcqdcGcGceccqdqeqf#qgcGcGc"
"ccdqcqBqAqBccqBqAqGqAcBqAqGqF#qGc";

const char ElBimbo[]=
"eqHqbqaqeqcccccccc"
"cccqeqHqbqaqeqgcgqfqfcfc"
"fcfqdqeqfqgqaq"
"HcHqbqbcbqaq"
"acaqgqgcgqfq"
"fcfqeqececec";

const char Hawaii[]=
"EqEqGcBcAcAcEcEcEc"
"EqEqDqGcEqEcEcEcEcEc"
"EqEqGqBcAqAcAqeqececec"
"dqdqBqGceqececececececececec"
"gceqdqcqAq"
"cqdqcqAqAcAcAc"
"acf#qeqdqBqAqBqFqGqGqAqBcAcAqeqececec"
"dqdqBqGcAqAcAcAcAc";

const char CocaCola[]=
"f#sf#sf#sf#sgqf#seqesasf#qdq";

const char AustinPowers[]=
"Bqc#sc#qeqc#s"
"F#seqc#qeqgs"
"esasgseseqeses"
"BsdqesBsdqesBs"
"DcDcEqBcDs"
"EsEsEsDsEsDsDs";

const char DaFunk[]=
"fcd#qfqg#qCcCs"
"A#scsd#sGcGs"
"g#scsFcGqG#q";

const char BarbieGirl[]=
"G#qEqG#qc#Acq"
"F#qD#qF#qBqG#cF#qEq"
"EqC#qF#cC#c"
"F#qEqG#cF#c";

const char odeToJoy1[]=
"EcEcFcGcGcFcEcDcCcCcDcEcEcEq"
"DqDcDcEcFcGcGcFcEcDcCcCcDcEcDcDqCqCcCc";

const char Beethovan5[]=
"EqEqEqCcDqDqDqBcBcEqEqEqFqFqFqCqCqCqAc"
"EqEqEqFqFqFqDqDqDqBcBqEqEqDqCcBqEqEqEqDq";

const char ForElise[]=
"eqd#qeqd#qeqBqd#qcqAcAq"
"CqEqAqBcBqeqg#qBqcccqEq"
"eqd#qeqd#qeqBqd#qcqAcAq"
"CqEqAqBcEqcqBqAcAq";

const char ChopinNocturne[]=
"GcececececdcecdcdcdcccccGcececAcacacecgcgcgcfcfcec"
"dcdcdcececBcccccccAcAcAcGcbcacgqfqeqfqAqBqcccccccc";

const char TheBlueDanube[]=
"CcCcEcGcGcgcgcececCcCcEcGcGcgcgcfcfc"
"BcBcDcAcAcacacfcfcBcBcDcAcAcacacecec"
"CcCcEcGcCcccccgcgcCcCcEcGcCcccccacac"
"DcDcFcAcAcAcF#cGcececccEcEcDqDc"
"AcGqGcCcCqCc";

const char Romanza[]=
"bqBqGqbqBqGqbqBqGqbqBqGq"
"aqBqGqgqBqGqgqBqGqF#qBqGq"
"EqBqGqEqBqGqgqBqGqbqBqGqeqBqGq"
"eqBqGqeqBqGqeqBqGqdqBqGq"
"cqBqGqcqEqCqbqEqCqaqEqCq"
"aqEqCqbqEqCqcqEqCqbqEqD#q"
"cqEqD#qbqEqD#qd#qEqD#qcqEqD#qbqEqD#q"
"bqBqGqaqBqGqgqBqGqgqBqGqEqBqGqF#qBqAq"
"F#qBqAqF#qBqAqF#qBqAqgqBqAqF#qBqAq"
"EqBqAqEqBqAqEqBqAqEc";

const char EndlessLove[]=
"FqcqGcFqGqG#qA#ccq"
"Fqfqd#qfqd#qA#qc#q"
"Fqfqd#qA#qcqc#qcqG#c"
"FqcqA#cGqFc";

const char Canon[]=
"acf#qgqacf#qgqaq"
"AqBqc#qdqeqf#qgq"
"f#cdqeqf#cF#qGqAqBqAqGqAqF#qGqAq"
"GcBqAqGcF#qEqF#qEqDqEqF#qGqAqBqGc"
"BqAqBcc#qdqAqBqc#qdqeqf#qgqaq"
"acf#qgqacf#qgqaq"
"AqBqc#qdqeqf#qgq"
"f#cdqeqf#cF#qGqAqBqAqGqAqF#qGqAq"
"GcBqAqGcF#qEqF#qEqDqEqF#qGqAqBqGc"
"BqAqBcc#qdqAqBqc#qdqeqf#qgqaq";

const char SaiMa[]=
"cqgqfsgsfsd#scqd#qcqGq"
"cqgqfsgsfsd#scqd#qcqGq"
"ccd#qfqfqd#qfqa#qgc"
"fqgqfqd#qfqd#qcc";

const char NasiLemak[]=
"FqDqEqFcGqGqA#cAcGqFqEqFq"
"ccGqAcFqGcEqFqFc"
"ccGqAcFqGcEqFq";

const char ThePrata[] = 
"a#ca#cfqfqfqd#qfqd#qdqd#qA#qA#qA#c"
"dqcqdqd#qf#qfqf#qa#qa#qa#c";

const char BuPaBuPa[] =
"dcc#qdqBcBqc#qBqAqF#c"
"dqf#qeqdc"
"AqAqeqdqc#c"
"dqc#qBqdcc#qdq"
"BqBqc#cBqAq"
"F#qdqf#ceqc#qeqcqdqBc";

const char YingYangChuo[] =
"A#cFqFqD#qFc"
"A#qc#qAqFc"
"A#qcqc#qcqA#qG#qD#qG#qFc"
"A#qA#qcqc#c"
"cqFqG#qF#c"
"D#qD#qFqF#qA#qcqc#qcc";

/*Phyoe Kyaw Kyaw - JoJo 0346788 DECC 3A05*/
const char BSong[]=
"CqCqDqCqFqEq"
"CqCqDqCqGqFq"
"CqCqcqAqFqEqDq"
"A#qA#qAqFqGqFq"
"CqCqDqCqFqEq"
"CqCqDqCqGqFq"
"CqCqcqAqFqEqDq"
"A#qA#qAqFqGqFq";
/*Phyoe Kyaw Kyaw - JoJo 0346788 DECC 3A05*/
const char RHW[]=
"CqFqcqgqgqfqeqdqdqeqfqeq"
"cqcqdqeqdqcqBqAqGq"
"CqFqcqgqgqfqeqdqdqeqfqeq"
"cqdqeqfqeqdqcqBqcq";
/*Phyoe Kyaw Kyaw - JoJo 0346788 DECC 3A05*/
const char JingleBell[] = 
"eqeqeqHqeqeqeqHqgqcqdqeq"
"HqfqfqfqHqfqeqeqHqeqdqdqgqdqHq"
"eqeqeqHqeqeqeqHqgqcqdqeq"
"HqfqfqfqHqfqeqeqHqgqfqfqdqcq";

const char Maestro[] =
"dcGqAqBqcqdcGcGceccqdqeqf#qgcGcGcccdqcqBqAqBccqBqAqGq"
"F#cGqAqBqGqBcAcAcdcGqAqBqcqdcGcGceccqdqeqf#qgcGcGc"
"ccdqcqBqAqBccqBqAqGqAcBqAqGqF#qGc";

/*Phyoe Kyaw Kyaw - JoJo 0346788 DECC 3A05*/
const char Myanmar[] =
"CqEqGqGqGqGqAqEqcqcqcqdqAqAqAqAqcqFqGqAqBqAqGqFqEqAq"
"AqGqFqEqDqGqGqFqEqDqCqCqDqEq"
"CqEqGqGqGqGqAqEqcqcqcqdqAqAqAqAqcqFqGqAqBqAqGqFqEqAq"
"AqGqFqEqDqGqGqFqEqDqCqCqDqEq";

/* composed by TANEEHOW EDECC/EO/4B21 P0606323 */
const char springmess[]=
"gcecececgcecececdcccdccccccccc"
"dcdcecfcfcfcdcececfcgcgcgcec"
"gcgcgcecgcgcgcecfcecdccccccccc";


const char kojo[]=
"ececacbcccbcacacfcfcecdcecececec"
"ececacbcccbcacacfcdcececAcAcAcAc"
"ccccBcAcfcfcececdcecfcfcecececec"
"ececacbcccbcacacfcdcececAcAcAcAc";

const char aura[]=
"GcccBcccdcAcdcdcccBcAcBccccccccc"
"GcccBcccdcAcdcdcccBcAcBccccccccc"
"ecececececececececdcccdcecececec"
"ececfcecdcAcdcdcecBcecdcecececec";

const char littlebrown[]=
"DcGcGcGcFcAcAcAcBcBcAcBcccdcecec"
"DcGcGcGcFcAcAcAcBcBcAcBccccccc"
"ecccGcGcFcAcAcAcGcBcBcBcAqGccccccc"
"ecccGcGcFcAcAcAcBcBcAcBccccccc";

const char polka[]=
"GcAcBcccdcdcdqccBc"
"ccccccqBqAcGcBcdc"
"ececeqdqccdcdcdqcqBc"
"cccccqBcAcGcBcdc";

const char OdeToJoy[]=
"EcEcFcGcGcFcEcDcCcCcDcEcEcEq"
"DqDcDcEcFcGcGcFcEcDcCcCcDcEcDcDqCqCcCc";

const char munchen[]=
"eceqgcdcdqeccccqecGcAcAcBcAqBcccecgc"
"eceqgcdcdqeccccqecGcAcAcBcAqBccccccc"
"fcaccagqfcecgcgcfqecdcfcfceqdcccecgc"
"fcacacgqfcecgcgcfqecdcfcfceqdccceccc"
"gqgqgqgqgcecgqgqgqgqgcecfqfqfqfqfcdcccacgc"
"gqgqgqgqgcec gqgqgqgqgcec fqfqfqfqfcdqBqBccccccc";

const char POLKA[]=
"ccccccccececececgcecececfcfcfcfcdcdcdcdceccccccc"
"ccccccccececececgcecececfcfcfcfcdcBccccccccc"
"ccdcecfcgcgcgcgcececececfcfcfcfcdcdcdcdceccccccc"
"ccdcecfcgcgcgcgcececececfcfcfcfcdcBccccccc";

const char attention[]=
"D#qA#qD#cA#qF#cFcD#cA#q"
"C#qG#qC#cD#cFc"
"A#sG#qC#cG#qFcD#cC#cG#q"
"BsF#qBqC#cD#c";
