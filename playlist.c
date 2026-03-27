/**
 * playlist.c
 *
 * Implementation of the Playlist ADT.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "playlist.h"

#define INITIAL_CAPACITY 10
#define CAPACITY_STEP 10

typedef struct _song
{
    char title[MAX_STRING_SIZE];
    char singer[MAX_STRING_SIZE];
    int year;
} song;

struct _playlist
{
    song *songs;
    int count;
    int capacity;
    int max_capacity;
};

playlist playlist_create(int _max_capacity)
{
    playlist new_p = malloc(sizeof(struct _playlist));
    if (new_p == NULL)
    {
        return NULL;
    }

    new_p->count = 0;
    new_p->capacity = INITIAL_CAPACITY;
    new_p->max_capacity = _max_capacity;

    if (new_p->max_capacity < INITIAL_CAPACITY)
    {
        new_p->capacity = new_p->max_capacity;
    }

    new_p->songs = malloc(new_p->capacity * sizeof(song));
    if (new_p->songs == NULL)
    {
        free(new_p);
        return NULL;
    }

    return new_p;
}

int playlist_destroy(playlist *_pl)
{
    if (_pl == NULL || *_pl == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    free((*_pl)->songs);
    free(*_pl);
    *_pl = NULL;

    return PLAYLIST_SUCCESS;
}

int playlist_add_song(playlist _pl, const char *_title, const char *_artist, int _year)
{
    if (_pl == NULL || _title == NULL || _artist == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    if (_pl->count >= _pl->max_capacity)
    {
        return PLAYLIST_ERROR_FULL;
    }

    if (_pl->count >= _pl->capacity)
    {
        int new_capacity = _pl->capacity + CAPACITY_STEP;
        if (new_capacity > _pl->max_capacity)
        {
            new_capacity = _pl->max_capacity;
        }

        song *temp = realloc(_pl->songs, new_capacity * sizeof(song));
        if (temp == NULL)
        {
            return PLAYLIST_ERROR_ALLOC;
        }

        _pl->songs = temp;
        _pl->capacity = new_capacity;
    }

    strncpy(_pl->songs[_pl->count].title, _title, MAX_STRING_SIZE - 1);
    _pl->songs[_pl->count].title[MAX_STRING_SIZE - 1] = '\0';

    strncpy(_pl->songs[_pl->count].singer, _artist, MAX_STRING_SIZE - 1);
    _pl->songs[_pl->count].singer[MAX_STRING_SIZE - 1] = '\0';

    _pl->songs[_pl->count].year = _year;
    _pl->count++;

    return PLAYLIST_SUCCESS;
}

int playlist_remove_song(playlist _pl, int _index)
{
    if (_pl == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    if (_index < 0 || _index >= _pl->count)
    {
        return PLAYLIST_ERROR_INDEX;
    }

    for (int i = _index; i < _pl->count - 1; i++)
    {
        _pl->songs[i] = _pl->songs[i + 1];
    }

    _pl->count--;

    return PLAYLIST_SUCCESS;
}

int playlist_get_count(playlist _pl, int *_result)
{
    if (_pl == NULL || _result == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    *_result = _pl->count;
    return PLAYLIST_SUCCESS;
}

int playlist_get_song(playlist _pl, int _index, char *_title, char *_artist, int *_year)
{
    if (_pl == NULL || _title == NULL || _artist == NULL || _year == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    if (_index < 0 || _index >= _pl->count)
    {
        return PLAYLIST_ERROR_INDEX;
    }

    strncpy(_title, _pl->songs[_index].title, MAX_STRING_SIZE);
    strncpy(_artist, _pl->songs[_index].singer, MAX_STRING_SIZE);
    *_year = _pl->songs[_index].year;

    return PLAYLIST_SUCCESS;
}

int playlist_print(playlist _pl)
{
    if (_pl == NULL)
    {
        return PLAYLIST_ERROR_NULL;
    }

    printf("\n--- PLAYLIST (%d/%d songs) ---\n", _pl->count, _pl->max_capacity);

    if (_pl->count == 0)
    {
        printf("The playlist is empty.\n");
    }
    else
    {
        for (int i = 0; i < _pl->count; i++)
        {
            printf("[%d] %s - %s (%d)\n",
                   i,
                   _pl->songs[i].title,
                   _pl->songs[i].singer,
                   _pl->songs[i].year);
        }
    }

    printf("------------------------------\n");

    return PLAYLIST_SUCCESS;
}