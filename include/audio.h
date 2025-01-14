#ifndef AUDIO_H
#define AUDIO_H

// Initializes SDL audio and Mixer
void init_audio();

// Plays a single sound effect
void play_sound(const char *file);

// Plays looping background music
void play_music(const char *file);

// Cleans up SDL audio and Mixer resources
void cleanup_audio();

#endif