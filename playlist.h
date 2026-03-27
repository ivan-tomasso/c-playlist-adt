/**
 * playlist.h
 *
 * Interface for the Playlist ADT (Abstract Data Type).
 * Provides operations to manage a collection of songs.
 */

#ifndef PLAYLIST_H
#define PLAYLIST_H

/* Constants */
#define MAX_STRING_SIZE 30

/* Return codes */
#define PLAYLIST_SUCCESS 0
#define PLAYLIST_ERROR_NULL -10
#define PLAYLIST_ERROR_FULL -20
#define PLAYLIST_ERROR_INDEX -30
#define PLAYLIST_ERROR_ALLOC -40

/* Opaque type (encapsulation) */
typedef struct _playlist *playlist;

/**
 * Creates a new playlist.
 *
 * @param _max_capacity Maximum number of songs allowed.
 * @return Pointer to the playlist, or NULL if allocation fails.
 */
playlist playlist_create(int _max_capacity);

/**
 * Frees all memory associated with the playlist.
 *
 * @param _pl Pointer to the playlist pointer.
 * @return PLAYLIST_SUCCESS on success, PLAYLIST_ERROR_NULL if invalid.
 */
int playlist_destroy(playlist *_pl);

/**
 * Adds a new song at the end of the playlist.
 *
 * @param _pl Playlist instance.
 * @param _title Song title.
 * @param _artist Song artist.
 * @param _year Release year.
 *
 * @return PLAYLIST_SUCCESS on success;
 *         PLAYLIST_ERROR_NULL if parameters are invalid;
 *         PLAYLIST_ERROR_FULL if max capacity is reached.
 */
int playlist_add_song(playlist _pl, const char *_title, const char *_artist, int _year);

/**
 * Removes a song at the given index.
 *
 * @param _pl Playlist instance.
 * @param _index Position of the song.
 *
 * @return PLAYLIST_SUCCESS on success;
 *         PLAYLIST_ERROR_NULL if playlist is NULL;
 *         PLAYLIST_ERROR_INDEX if index is invalid.
 */
int playlist_remove_song(playlist _pl, int _index);

/**
 * Retrieves the current number of songs.
 *
 * @param _pl Playlist instance.
 * @param _result Pointer where the count will be stored.
 *
 * @return PLAYLIST_SUCCESS on success;
 *         PLAYLIST_ERROR_NULL if parameters are invalid.
 */
int playlist_get_count(playlist _pl, int *_result);

/**
 * Retrieves song information at a given index.
 *
 * NOTE: Caller must provide buffers large enough for title and artist.
 *
 * @param _pl Playlist instance.
 * @param _index Position of the song.
 * @param _title Output buffer for the title.
 * @param _artist Output buffer for the artist.
 * @param _year Pointer where the year will be stored.
 *
 * @return PLAYLIST_SUCCESS on success;
 *         PLAYLIST_ERROR_NULL if parameters are invalid;
 *         PLAYLIST_ERROR_INDEX if index is invalid.
 */
int playlist_get_song(playlist _pl, int _index, char *_title, char *_artist, int *_year);

/**
 * Prints the playlist to standard output.
 *
 * @param _pl Playlist instance.
 * @return PLAYLIST_SUCCESS on success;
 *         PLAYLIST_ERROR_NULL if playlist is NULL.
 */
int playlist_print(playlist _pl);

#endif