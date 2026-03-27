/**
 * main.c
 *
 * Driver program and test suite for the Playlist ADT.
 */

#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

int main(void)
{
    printf("=== Playlist ADT Test Suite ===\n\n");

    /* 1. Create a playlist with a max capacity of 3 */
    printf("[Test 1] Creating a playlist with max capacity 3...\n");
    playlist my_pl = playlist_create(3);
    if (my_pl == NULL)
    {
        printf("Error: Failed to create playlist.\n");
        return 1;
    }
    printf("Success: Playlist created.\n\n");

    /* 2. Add songs to the playlist */
    printf("[Test 2] Adding 3 songs...\n");
    playlist_add_song(my_pl, "Bohemian Rhapsody", "Queen", 1975);
    playlist_add_song(my_pl, "Stairway to Heaven", "Led Zeppelin", 1971);
    playlist_add_song(my_pl, "Hotel California", "Eagles", 1976);
    playlist_print(my_pl);

    /* 3. Test capacity limit (Should fail) */
    printf("\n[Test 3] Trying to add a 4th song (Testing max capacity)...\n");
    int res = playlist_add_song(my_pl, "Imagine", "John Lennon", 1971);
    if (res == PLAYLIST_ERROR_FULL)
    {
        printf("Success: Playlist correctly rejected the song (Error Code: %d).\n", res);
    }
    else
    {
        printf("Fail: Expected a FULL error, but got %d.\n", res);
    }

    /* 4. Test retrieving a specific song */
    printf("\n[Test 4] Retrieving song at index 1...\n");
    char title[MAX_STRING_SIZE];
    char artist[MAX_STRING_SIZE];
    int year;

    if (playlist_get_song(my_pl, 1, title, artist, &year) == PLAYLIST_SUCCESS)
    {
        printf("Retrieved: '%s' by %s (%d)\n", title, artist, year);
    }

    /* 5. Test removing a song */
    printf("\n[Test 5] Removing song at index 0 (Bohemian Rhapsody)...\n");
    playlist_remove_song(my_pl, 0);
    playlist_print(my_pl);

    /* 6. Test getting the current count */
    printf("\n[Test 6] Getting current song count...\n");
    int count = 0;
    if (playlist_get_count(my_pl, &count) == PLAYLIST_SUCCESS)
    {
        printf("Current number of songs: %d\n", count);
    }

    /* 7. Clean up memory */
    printf("\n[Test 7] Destroying playlist and freeing memory...\n");
    playlist_destroy(&my_pl);

    if (my_pl == NULL)
    {
        printf("Success: Playlist destroyed safely. Pointer is NULL.\n");
    }

    printf("\n=== All Tests Completed ===\n");
    return 0;
}