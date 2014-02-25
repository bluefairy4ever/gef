/*
Musical note library
*/

#include <Eyes.h>

const unsigned int LEFT_EYE_PIN = 13;
const unsigned int RIGHT_EYE_PIN = 10;

const unsigned int STANDARD_TEMPO = 1000;

Eyes eyes(LEFT_EYE_PIN, RIGHT_EYE_PIN);

enum DURATION_NAMES {
  SIXTEENTH, EIGHTH, QUARTER, DOTTED_QUARTER, HALF,
  WHOLE, TRIPLET
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
  STANDARD_TEMPO,
  8, EIGHTH, e7, e7, REST, e7, REST, c7, e7, REST,
  4, QUARTER, g7, REST, g6, REST,
  
  FIN
};

const unsigned int MARIO_GROUND_THEME_PART1[] = {
  STANDARD_TEMPO,
  1, QUARTER, c7, 2, EIGHTH, REST, g6, 2, QUARTER, REST, e6,
  6, EIGHTH, REST, a6, REST, b6, REST, _b6, 1, QUARTER,  a6,
  3, TRIPLET, g6, e7, g7, 1, QUARTER, a7, 2, EIGHTH, f7, g7,
  6, EIGHTH, REST, e7, REST, c7, d7, b6, 1, QUARTER,  REST,
  
  FIN
};

const unsigned int MARIO_GROUND_THEME_PART2[] = {
  STANDARD_TEMPO,
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
  STANDARD_TEMPO,
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
  STANDARD_TEMPO,
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
  Tempo() {
    resetTempo();
  }
  
  Tempo(unsigned int wholeNoteDuration) {
    setTempo(wholeNoteDuration);
  }
  
  void resetTempo() {
    setTempo(DEFAULT_WHOLE_NOTE_DURATION);
  }
  
  void setTempo(unsigned int wholeNoteDuration) {
    _sixteenth = wholeNoteDuration / 16;
    _eighth = wholeNoteDuration / 8;
    _quarter = wholeNoteDuration / 4;
    _triplet = _quarter / 3;
    _dottedQuarter = _quarter + _eighth;
    _half = wholeNoteDuration / 2;
    _whole = wholeNoteDuration;
    _doubleWhole = wholeNoteDuration * 2;
  }
  
  unsigned int getDuration(unsigned int durationName) {
    switch(durationName) {
      case SIXTEENTH: return _sixteenth;
      case EIGHTH: return _eighth;
      case QUARTER: return _quarter;
      case DOTTED_QUARTER: return _dottedQuarter;
      case HALF: return _half;
      case WHOLE: return _whole;
      case TRIPLET: return _triplet;
    }
  }
  
private:
  static const unsigned int DEFAULT_WHOLE_NOTE_DURATION = 1000;
  
  unsigned int _sixteenth;
  unsigned int _eighth;
  unsigned int _quarter;
  unsigned int _dottedQuarter;
  unsigned int _half;
  unsigned int _whole;
  unsigned int _doubleWhole;
  unsigned int _triplet;
};

class Song {
public:
  Song(const unsigned int* songArray) {
    _tempo = new Tempo(songArray[0]);
    parseSongArray(songArray);
  }
  
  void play();
  void play(unsigned int numLoops);
  
private:
  unsigned int* _pitches;
  unsigned int* _durations;
  unsigned int _totalNotes;
  Tempo* _tempo;
        
  void parseSongArray(const unsigned int* songArray);
  unsigned int getNumberOfNotes(const unsigned int* songArray);
  
};

class SongManager {
public:
  SongManager(unsigned int totalSongs);
  ~SongManager();
  int addSong(const unsigned int* songArray);
  int addSong(Song* song);
  void playSongAtPosition(unsigned int position);
  void playSongAtPosition(unsigned int position, unsigned int numLoops);

private:
  Song** _songList;
  unsigned int _totalSongs;
  unsigned int _currPosition;
  
};

void setup() {
  Serial.begin(9600);
        
  eyes.toggle();
  
  int marioThemePosition, happyBirthdayPosition;
  
  SongManager songManager(4);
  Song marioTheme(MARIO_GROUND_THEME);
  
  marioThemePosition = songManager.addSong(&marioTheme);
  
  //songManager.addSong(MARIO_GROUND_THEME_INTRO);
  //songManager.addSong(MARIO_GROUND_THEME_PART1);
  //songManager.addSong(MARIO_GROUND_THEME_PART2);
  happyBirthdayPosition = songManager.addSong(HAPPY_BIRTHDAY);
  
  songManager.playSongAtPosition(marioThemePosition);
  
  //songManager.playSongAtPosition((unsigned int)0);
  //songManager.playSongAtPosition(1, 2);
  //songManager.playSongAtPosition(2, 2);
  //songManager.playSongAtPosition(3); 
  
}

void loop() {
  
}

SongManager::SongManager(unsigned int totalSongs) : _totalSongs(totalSongs),
  _currPosition(0) {
}

SongManager::~SongManager() {
  for(int i=0; i<_totalSongs; i++) {
    delete _songList[i];
  }
  
  delete _songList;
}

int SongManager::addSong(const unsigned int* songArray) {
  if(_currPosition < _totalSongs) {
    _songList[_currPosition] = new Song(songArray);
  } else {
    Serial.println("No more positions available in song list.");
  }
  
  return _currPosition++;
}

int SongManager::addSong(Song* song) {
  if(_currPosition < _totalSongs) {
    _songList[_currPosition] = song;
  } else {
    Serial.println("No more positions available in song list.");
  }
  
  return _currPosition++;  
}

void SongManager::playSongAtPosition(unsigned int position) {
  playSongAtPosition(position, 1);
}

void SongManager::playSongAtPosition(unsigned int position, unsigned int numLoops) {
  if(position < _totalSongs && _songList[position] != NULL) {
    _songList[position]->play();
  } else {
    Serial.print("Cannot play song at position ");
    Serial.print(position);
    Serial.print(" as a song has not been loaded yet or the position is out of bounds.");
  }
}

void Song::play() {
  play(1);
}

void Song::play(unsigned int numLoops) {
  for(int currLoop=0; currLoop<numLoops; currLoop++) {
    for(int i=0; _pitches[i]!=FIN; i++) {
      //Serial.print(PITCHES[pitches[i]]);
      //Serial.print(", ");
      //Serial.println(durations[i]);
      
      if(_pitches[i] != REST) {
        eyes.toggle();
        tone(4, PITCHES[_pitches[i]], _durations[i]);
      }
      
      delay(_durations[i]);
      
      if(_pitches[i] != REST) {
        eyes.toggle();
      }
    }
  }
}

void Song::parseSongArray(const unsigned int* songArray) {
  //Serial.println("Populating the music arrays...");

  unsigned int songIndex, currIndex, currNumNotes;
    
  _pitches = new unsigned int[_totalNotes];
  _durations = new unsigned int[_totalNotes];
  
  songIndex = currIndex = 0;
  
  // Get the number of notes for this beat type
  currNumNotes = songArray[songIndex++];
  while(currNumNotes != FIN) {
    
    // Get the beat type
    unsigned int durationType = songArray[songIndex++];
    
    // Get the pitches for each note of this beat type
    for(; currNumNotes>0; currNumNotes--) {
      //Serial.print("Note: "); Serial.println(song[songIndex]);
      //Serial.print("Length: "); Serial.println(beat);
      
      _pitches[currIndex] = songArray[songIndex++];
      _durations[currIndex++] = _tempo->getDuration(durationType);
    }
    
    // Get the number of notes for this beat type
    currNumNotes = songArray[songIndex++];
  }
  
  _pitches[currIndex] = _durations[currIndex] = PITCHES[FIN];
}

unsigned int Song::getNumberOfNotes(const unsigned int* songArray) {
  //Serial.println("Calculating number of notes in the song...");
  
  unsigned int songIndex, totalNotes, currNumNotes;  
  songIndex = totalNotes = 0;  
  
  currNumNotes = songArray[songIndex];
  while(currNumNotes != FIN) {
    //Serial.print("Adding ");
    //Serial.print(currNumNotes);
    //Serial.println(" notes.");
    
    totalNotes += currNumNotes;
    songIndex += 2 + currNumNotes;
    
    currNumNotes = songArray[songIndex];
  }
  
  //Serial.print("Total notes in the song: ");
  //Serial.println(totalNotes);
  
  return totalNotes;
}
