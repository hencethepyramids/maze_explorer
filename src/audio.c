#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>

int init_audio() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        fprintf(stderr, "SDL Init Error: %s\n", SDL_GetError());
        return 0; // Indicate failure
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "Mix Open Audio Error: %s\n", Mix_GetError());
        SDL_Quit();
        return 0; // Indicate failure
    }
    return 1; // Indicate success
}

void play_sound(const char *file) {
    Mix_Chunk *sound = Mix_LoadWAV(file);
    if (!sound) {
        fprintf(stderr, "Sound Error: %s\n", Mix_GetError());
        return;
    }
    Mix_PlayChannel(-1, sound, 0);
    Mix_FreeChunk(sound);
}

void play_music(const char *file) {
    Mix_Music *music = Mix_LoadMUS(file);
    if (!music) {
        fprintf(stderr, "Music Error: %s\n", Mix_GetError());
        return;
    }
    Mix_PlayMusic(music, -1); // Loop infinitely
}

void cleanup_audio() {
    Mix_CloseAudio();
    SDL_Quit();
}