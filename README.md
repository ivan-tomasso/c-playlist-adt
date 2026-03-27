
# C Playlist ADT 

A Playlist Abstract Data Type (ADT) written in C, built as a university exercise at UNIMOL. The project explores dynamic memory management, data encapsulation via opaque pointers, and safe string handling.

---

## Project Structure

```text
c-playlist-adt/
├── playlist.h   # Public API, opaque type, and return codes
├── playlist.c   # Internal implementation of data structures and logic
└── main.c       # Test driver — 7 tests
````

-----

## Return Codes Reference

All functions return an integer code indicating success or the type of failure.

| Code                   | Value | Meaning                        |
|------------------------|-------|--------------------------------|
| `PLAYLIST_SUCCESS`     | `0`   | Operation successful           |
| `PLAYLIST_ERROR_NULL`  | `-10` | NULL pointer argument          |
| `PLAYLIST_ERROR_FULL`  | `-20` | Max capacity reached           |
| `PLAYLIST_ERROR_INDEX` | `-30` | Index out of range             |
| `PLAYLIST_ERROR_ALLOC` | `-40` | Memory allocation failed       |

-----

## Build & Run

To test the ADT using the provided test suite, you need GCC or any compatible compiler.

1.  **Clone the repository:**

    ```bash
    git clone https://github.com/ivan-tomasso/c-playlist-adt.git
    ```

2.  **Compile the source code:**

    ```bash
    gcc -Wall -Wextra -std=c99 -o playlist main.c playlist.c
    ```

3.  **Run the executable:**

      - On Windows: `.\playlist`
      - On macOS/Linux: `./playlist`

-----

## Author

**Ivan Tomasso** — CS Student @ UNIMOL  
[LinkedIn](https://linkedin.com/in/ivan-tomasso) · [GitHub](https://github.com/ivan-tomasso)


