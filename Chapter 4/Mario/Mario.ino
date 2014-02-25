/*
Musical note library
*/

#include <Eyes.h>

const unsigned int LEFT_EYE_PIN = 13;
const unsigned int RIGHT_EYE_PIN = 10;

Eyes eyes(LEFT_EYE_PIN, RIGHT_EYE_PIN);

enum LENGTHS {
  SIXTEENTH= 100, EIGHTH= 200, QUARTER= 400, DOTTED_QUARTER= 600, HALF= 800,
  WHOLE= 1600, TRIPLET= 267
};

const unsigned int PITCHES[] = { 0, 1,
  1047, 1109, 1109, 1175, 1245, 1245, 1319, 1397, 1319, 1397,
  1480, 1480, 1568, 1661, 1661, 1760, 1865, 1865, 1976, 2093,
  1976, 2093, 2218, 2218, 2349, 2489, 2489, 2637, 2794, 2637,
  2794, 2960, 2960, 3136, 3322, 3322, 3520, 3729, 3729, 3951,
  4186, 3951, 4186
};
  
enum PITCH_INDICES {
  FIN, REST, c6, c6_, _d6, d6, d6_, _e6, e6, e6_, _f6, f6,
  f6_, _g6, g6, g6_, _a6, a6, a6_, _b6, b6, b6_,
  _c7, c7, c7_, _d7, d7, d7_, _e7, e7, e7_, _f7,
  f7, f7_, _g7, g7, g7_, _a7, a7, a7_, _b7, b7,
  b7_, _c8, c8, TOTAL_PITCHES
};

const unsigned int MARIO_PITCH_INDICES[] = {
  e7, e7, REST, e7, REST, c7, e7, REST,
  g7, REST, g6, REST,
  
  c7, REST, g6, REST, e6, 
  REST, a6, REST, b6, REST, _b6, a6,
  g6, e7, g7, a7, f7, g7,
  REST, e7, REST, c7, d7, b6, REST,    
  
  c7, REST, g6, REST, e6, 
  REST, a6, REST, b6, REST, _b6, a6,
  g6, e7, g7, a7, f7, g7,
  REST, e7, REST, c7, d7, b6, REST,
  
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, g6_, a6, c7, REST, a6, c7, d7,
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, c8, REST, c8, c8, REST,
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, g6_, a6, c7, REST, a6, c7, d7,
  REST, _e7, REST, d7, REST,
  c7, REST, REST,
  
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, g6_, a6, c7, REST, a6, c7, d7,
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, c8, REST, c8, c8, REST,
  REST, g7, _g7, f7, d7_, REST, e7,
  REST, g6_, a6, c7, REST, a6, c7, d7,
  REST, _e7, REST, d7, REST,
  c7, REST, REST,
  
  FIN
};

const unsigned int MARIO_NOTE_LENGTHS[] = {
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, QUARTER, QUARTER, QUARTER, 
  
  QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER, 
  TRIPLET, TRIPLET, TRIPLET, QUARTER, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER,
  
  QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER, 
  TRIPLET, TRIPLET, TRIPLET, QUARTER, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER,
  
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER, QUARTER,
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, QUARTER, EIGHTH, EIGHTH, QUARTER,
  QUARTER, QUARTER, HALF,
  
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, QUARTER, QUARTER,
  QUARTER, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH, EIGHTH,
  QUARTER, QUARTER, EIGHTH, EIGHTH, QUARTER,
  QUARTER, QUARTER, HALF,
  
  FIN
};

const unsigned int MARIO_GROUND_THEME_INTRO[] = {
  8, EIGHTH, e7, e7, REST, e7, REST, c7, e7, REST,
  4, QUARTER, g7, REST, g6, REST,
  
  FIN
};

const unsigned int MARIO_GROUND_THEME_PART1[] = {
  1, QUARTER, c7, 2, EIGHTH, REST, g6, 2, QUARTER, REST, e6,
  6, EIGHTH, REST, a6, REST, b6, REST, _b6, 1, QUARTER,  a6,
  3, TRIPLET, g6, e7, g7, 1, QUARTER, a7, 2, EIGHTH, f7, g7,
  6, EIGHTH, REST, e7, REST, c7, d7, b6, 1, QUARTER,  REST,
  
  FIN
};

const unsigned int MARIO_GROUND_THEME_PART2[] = {
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  4, EIGHTH,  REST, c8, REST, c8, 2, QUARTER, c8, REST,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  2, QUARTER, REST, _e7, 2, EIGHTH, REST, d7, 1, QUARTER, REST,
  2, QUARTER, c7, REST, 1, HALF, REST,
  
  FIN 
};

const unsigned int MARIO_GROUND_THEME[] = {
  8, EIGHTH, e7, e7, REST, e7, REST, c7, e7, REST,
  4, QUARTER, g7, REST, g6, REST,
  
  1, QUARTER, c7, 2, EIGHTH, REST, g6, 2, QUARTER, REST, e6,
  6, EIGHTH, REST, a6, REST, b6, REST, _b6, 1, QUARTER,  a6,
  3, TRIPLET, g6, e7, g7, 1, QUARTER, a7, 2, EIGHTH, f7, g7,
  6, EIGHTH, REST, e7, REST, c7, d7, b6, 1, QUARTER,  REST,
  
  1, QUARTER, c7, 2, EIGHTH, REST, g6, 2, QUARTER, REST, e6,
  6, EIGHTH, REST, a6, REST, b6, REST, _b6, 1, QUARTER,  a6,
  3, TRIPLET, g6, e7, g7, 1, QUARTER, a7, 2, EIGHTH, f7, g7,
  6, EIGHTH, REST, e7, REST, c7, d7, b6, 1, QUARTER,  REST,
  
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  4, EIGHTH,  REST, c8, REST, c8, 2, QUARTER, c8, REST,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  2, QUARTER, REST, _e7, 2, EIGHTH, REST, d7, 1, QUARTER, REST,
  2, QUARTER, c7, REST, 1, HALF, REST,
  
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  4, EIGHTH,  REST, c8, REST, c8, 2, QUARTER, c8, REST,
  1, QUARTER, REST, 6, EIGHTH, g7, _g7, f7, d7_, REST, e7,
  8, EIGHTH, REST, g6_, a6, c7, REST, a6, c7, d7,
  2, QUARTER, REST, _e7, 2, EIGHTH, REST, d7, 1, QUARTER, REST,
  2, QUARTER, c7, REST, 1, HALF, REST,
  
  FIN
};

const unsigned int HAPPY_BIRTHDAY[] = {
  2, EIGHTH, d6, d6,
  3, QUARTER, e6, d6, g6,
  1, DOTTED_QUARTER, f6_, 3, EIGHTH, REST, d6, d6,
  3, QUARTER, e6, d6, a6,
  1, DOTTED_QUARTER, g6, 3, EIGHTH, REST, d6, d6,
  3, QUARTER, d7, b6, g6,
  1, QUARTER, f6_, 4, EIGHTH, e6, REST, c7, c7,
  3, QUARTER, b6, g6, a6,
  1, WHOLE, g6,
  
  FIN
};

class Tempo {
public:
  Tempo(unsigned int wholeNoteDuration) {
    setTempo(wholeNoteDuration);
  }
  
  void setTempo(unsigned int wholeNoteDuration) {
    _doubleWhole = wholeNoteDuration * 2;
    _whole = wholeNoteDuration;
    _half = wholeNoteDuration / 2;
    _quarter = wholeNoteDuration / 4;
    _eighth = wholeNoteDuration / 8;
    _sixteenth = wholeNoteDuration / 16;
  }
  
private:
  unsigned int _sixteenth;
  unsigned int _eighth;
  unsigned int _quarter;
  unsigned int _half;
  unsigned int _whole;
  unsigned int _doubleWhole;
  unsigned int _triplet;
};

class SongManager {
public:
  SongManager(unsigned int totalSongs);
  ~SongManager();
  int addSong(const unsigned int* song);
  void playSong(unsigned int position);
  void playSong(unsigned int position, unsigned int numLoops);
  static void playSong(const unsigned int* song);
  static void playSong(const unsigned int* song, unsigned int numLoops);

private:
  unsigned int*** _songList;
  unsigned int _totalSongs;
  unsigned int _currPosition;
  Tempo* _tempo;
      
  /*class Song {
  public:
    Song(const unsigned int* song, unsigned int wholeNoteDuration) {
      populateNoteArrays(song, _pitches, _durations);
      _tempo = new Tempo(wholeNoteDuration);
    }
  private:
    unsigned int* _pitches;
    unsigned int* _durations;
    unsigned int _totalNotes;
    Tempo* _tempo;
    
  };*/
  
  static void playSong(unsigned int*& songNotes, unsigned int*& songNoteLengths, unsigned int numLoops);
  static void populateSongArrays(const unsigned int* song, unsigned int*& notes, unsigned int*& noteLengths);
  static unsigned int getNumberOfNotes(const unsigned int* song);
  
};

void setup() {
  Serial.begin(9600);
        
  eyes.toggle();
  
  SongManager songManager(4);
  
  //songManager.addSong(MARIO_GROUND_THEME_INTRO);
  //songManager.addSong(MARIO_GROUND_THEME_PART1);
  //songManager.addSong(MARIO_GROUND_THEME_PART2);
  //songManager.addSong(HAPPY_BIRTHDAY);
  
  //songManager.playSong((unsigned int)0);
  //songManager.playSong(1, 2);
  //songManager.playSong(2, 2);
  //songManager.playSong(3);
  
  SongManager::playSong(MARIO_GROUND_THEME);
  //SongManager::playSong(HAPPY_BIRTHDAY);
}

void loop() {
  
  eyes.toggle();
  delay(1000);
}

SongManager::SongManager(unsigned int totalSongs) : _totalSongs(totalSongs),
  _currPosition(0) {
  _songList = new unsigned int**[_totalSongs];
  _tempo = new Tempo(1000);
}

SongManager::~SongManager() {
  for(int i=0; i<_totalSongs; i++) {
    for(int j=0; j<2; j++) {
      delete _songList[i][j];
    }
    
    delete _songList[i];
  }
  
  delete _songList;
  delete _tempo;
}

int SongManager::addSong(const unsigned int* song) {
  if(_currPosition < _totalSongs) {
    _songList[_currPosition] = new unsigned int*[2];
    populateSongArrays(song, _songList[_currPosition][0], _songList[_currPosition++][1]);
  } else {
    Serial.println("No more positions available in song list.");
  }
}

void SongManager::playSong(unsigned int position) {
  if(position < _totalSongs && _songList[position] != NULL) {
    playSong(_songList[position][0], _songList[position][1], 1);
  } else {
    Serial.print("Cannot play song at position ");
    Serial.print(position);
    Serial.print(" as a song has not been loaded yet or the position is out of bounds.");
  }
}

void SongManager::playSong(unsigned int position, unsigned int numLoops) {
  if(position < _totalSongs && _songList[position] != NULL) {
    playSong(_songList[position][0], _songList[position][1], numLoops);
  } else {
    Serial.print("Cannot play song at position ");
    Serial.print(position);
    Serial.print(" as a song has not been loaded yet or the position is out of bounds.");
  }
}
  
void SongManager::playSong(const unsigned int* song) {
  playSong(song, 1);
}

void SongManager::playSong(const unsigned int* song, unsigned int numLoops) {
  unsigned int *songNotes, *songNoteLengths;
  songNotes = songNoteLengths = NULL;
  
  populateSongArrays(song, songNotes, songNoteLengths);
  
  playSong(songNotes, songNoteLengths, numLoops);
  
  delete songNotes;
  delete songNoteLengths;
}

void SongManager::playSong(unsigned int*& songNotes, unsigned int*& songNoteLengths, unsigned int numLoops) {
  
  for(int currLoop=0; currLoop<numLoops; currLoop++) {
    for(int i=0; songNotes[i]!=FIN; i++) {
      //Serial.print(PITCHES[songNotes[i]]);
      //Serial.print(", ");
      //Serial.println(songNoteLengths[i]);
      
      if(songNotes[i] != REST) {
        eyes.toggle();
        tone(4, PITCHES[songNotes[i]], songNoteLengths[i]);
      }
      
      delay(songNoteLengths[i]);
      
      if(songNotes[i] != REST) {
        eyes.toggle();
      }
    }
  }
}

void SongManager::populateSongArrays(const unsigned int* song, unsigned int*& notes, unsigned int*& noteLengths) {
  //Serial.println("Populating the music arrays...");

  unsigned int songIndex, totalNotes, currIndex, currNumNotes;
  
  totalNotes = getNumberOfNotes(song);
  notes = new unsigned int[totalNotes];
  noteLengths = new unsigned int[totalNotes];
  
  songIndex = currIndex = 0;  
  currNumNotes = song[songIndex++];
  while(currNumNotes != FIN) {
    
    unsigned int beat = song[songIndex++];
      
    for(; currNumNotes>0; currNumNotes--) {
      //Serial.print("Note: "); Serial.println(song[songIndex]);
      //Serial.print("Length: "); Serial.println(beat);
      
      notes[currIndex] = song[songIndex++];
      noteLengths[currIndex++] = beat;
    }
    
    currNumNotes = song[songIndex++];
  }
  
  notes[currIndex] = noteLengths[currIndex] = PITCHES[FIN];
}

unsigned int SongManager::getNumberOfNotes(const unsigned int* song) {
  //Serial.println("Calculating number of notes in the song...");
  
  unsigned int songIndex, totalNotes, currNumNotes;
  songIndex = totalNotes = 0;  
  
  currNumNotes = song[songIndex];
  while(currNumNotes != FIN) {
    //Serial.print("Adding ");
    //Serial.print(currNumNotes);
    //Serial.println(" notes.");
    
    totalNotes += currNumNotes;
    songIndex += 2 + currNumNotes;
    
    currNumNotes = song[songIndex];
  }
  
  //Serial.print("Total notes in the song: ");
  //Serial.println(totalNotes);
  
  return totalNotes;
}
