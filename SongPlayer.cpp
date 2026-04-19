/*****************************************
** File:    SongPlayer.cpp
** Project: CMSC 202 Project 5, Fall 2025
** Author:  Amit Reddy
** Date:    11/18/2025
** Section: 32
** Email:   amitr2@@umbc.edu
**
** Description: Implementation of SongPlayer class
*****************************************/ 

#include "SongPlayer.h"
using namespace std;

//-------------------------------------------------------
// Name: SongPlayer (Default Constructor)
// Desc: Initializes SongPlayer with default file name
//-------------------------------------------------------
SongPlayer::SongPlayer() {
    m_filename = FILE_NAME;
}

//-------------------------------------------------------
// Name: SongPlayer (Overloaded Constructor)
// Desc: Initializes SongPlayer with chosen filename
//-------------------------------------------------------
SongPlayer::SongPlayer(string filename) {
    m_filename = filename;
}

//-------------------------------------------------------
// Name: ~SongPlayer (Destructor)
// Desc: Deallocates all songs in catalog & playlist
//-------------------------------------------------------
SongPlayer::~SongPlayer() {
    for (size_t i = 0; i < m_songCatalog.size(); i++) {
        delete m_songCatalog[i];
    }
    m_songCatalog.clear();
    m_playList.Clear();
}

//-------------------------------------------------------
// Name: ToLower
// Desc: Converts a string to lowercase
//-------------------------------------------------------
string SongPlayer::ToLower(string word) {
    for (unsigned int i = 0; i < word.size(); i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

//-------------------------------------------------------
// Name: LoadCatalog
// Desc: Loads songs from txt file into songCatalog
//-------------------------------------------------------
void SongPlayer::LoadCatalog() {
    ifstream inFile(m_filename);
    if (!inFile.is_open()) {
        return;
    }

    string title, album, artist, s1, s2, s3;
    while (getline(inFile, title, '|')) {
        getline(inFile, album, '|');
        getline(inFile, artist, '|');
        getline(inFile, s1, '|');
        getline(inFile, s2, '|');
        getline(inFile, s3);

        // Convert strings to long
        long spotify = stol(s1);
        long youtube = stol(s2);
        long tiktok  = stol(s3);

        Song* temp = new Song(title, album, artist, spotify, youtube, tiktok);
        m_songCatalog.push_back(temp);
    }
    inFile.close();

    cout << "Welcome to UMBC Song Player" << endl;
    cout << m_songCatalog.size() << " song files loaded." << endl << endl;
}

//-------------------------------------------------------
// Name: SearchOptions
// Desc: Ask user if searching by artist or title
//-------------------------------------------------------
int SongPlayer::SearchOptions() {
    int choice = 0;
    while (choice != 1 && choice != 2) {
        cout << "Would you rather search by artist or title?" << endl;
        cout << "1. Artist" << endl;
        cout << "2. Title" << endl;
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(256, '\n');
    }
    return choice;
}

//-------------------------------------------------------
// Name: SearchType
// Desc: Prompts user to enter the name/title to search
//-------------------------------------------------------
string SongPlayer::SearchType(string type) {
    string input;
    cout << "Which " << type << " would you like to display? ";
    getline(cin, input);
    return input;
}

//-------------------------------------------------------
// Name: DisplaySong
// Desc: Displays search results by artist or title
//-------------------------------------------------------
int SongPlayer::DisplaySong() {
    int option = SearchOptions();
    string type = (option == 1) ? "artist" : "title";
    string search = ToLower(SearchType(type));

    int count = 0;
    for (size_t i = 0; i < m_songCatalog.size(); i++) {
        Song* s = m_songCatalog[i];
        string titleLower = ToLower(s->GetTitle());
        string artistLower = ToLower(s->GetArtist());

        if (option == 1 && artistLower.find(search) != string::npos) {
            cout << i + 1 << " " << *s << endl;
            count++;
        }
        else if (option == 2 && 
            (titleLower.find(search) != string::npos ||
            artistLower.find(search) != string::npos)) {
            cout << i + 1 << " " << *s << endl;
            count++;
        }
    }

    if (count == 0) {
        cout << "No songs found with those criteria." << endl << endl;
    } else {
        cout << count << " songs found." << endl << endl;
    }
    return count;
}

//-------------------------------------------------------
// Name: AddSong
// Desc: Adds ANY valid song# to playlist (even if not in search)
//-------------------------------------------------------
void SongPlayer::AddSong() {
    cout << "Choose the song you would like to add to the playlist." << endl;
    int found = DisplaySong();
    if (found == 0) return;

    int choice;
    cout << "Enter the number of the song you would like to add: ";
    cin >> choice;
    cin.ignore(256, '\n');

    if (choice >= 1 && choice <= (int)m_songCatalog.size()) {
        Song* s = m_songCatalog[choice - 1];
        m_playList.PushBack(s);
        cout << *s << " added to the playlist." << endl << endl;
    }
}

//-------------------------------------------------------
// Name: DisplayPlaylist
// Desc: Displays playlist songs numbered 1, 2, 3,...
//-------------------------------------------------------
void SongPlayer::DisplayPlaylist() {
    if (m_playList.IsEmpty()) {
        cout << "Playlist is empty." << endl << endl;
        return;
    }
    for (int i = 0; i < m_playList.GetSize(); i++) {
        cout << i + 1 << ". " << *m_playList.At(i) << endl;
    }
    cout << endl;
}

//-------------------------------------------------------
// Name: SortPlaylist
// Desc: Sorts playlist by Spotify streams (descending)
//-------------------------------------------------------
void SongPlayer::SortPlaylist() {
    if (m_playList.GetSize() < 2) {
        cout << "Need at least 2 songs to sort." << endl << endl;
        return;
    }

    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < m_playList.GetSize(); i++) {
            Song* prev = m_playList.At(i - 1);
            Song* curr = m_playList.At(i);
            if (prev->GetSpotify() < curr->GetSpotify()) {
                m_playList.Swap(i);
                swapped = true;
            }
        }
    }
    cout << "Done sorting by Spotify streams" << endl;
    cout << m_playList.GetSize() << " items sorted." << endl << endl;
}

//-------------------------------------------------------
// Name: StartPlayer
// Desc: Starts program by loading catalog + menu
//-------------------------------------------------------
void SongPlayer::StartPlayer() {
    LoadCatalog();
    MainMenu();
}

//-------------------------------------------------------
// Name: MainMenu
// Desc: Displays menu and controls user choices
//-------------------------------------------------------
void SongPlayer::MainMenu() {
    int choice = 0;
    while (choice != 5) {
        cout << "What would you like to do?" << endl;
        cout << "1. Display Song by Title, Artist, and Album\n";
        cout << "2. Add Song to Playlist\n";
        cout << "3. Display Playlist\n";
        cout << "4. Sort Playlist by Spotify Streams\n";
        cout << "5. Quit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(256, '\n');

        if (choice == 1) DisplaySong();
        if (choice == 2) AddSong();
        if (choice == 3) DisplayPlaylist();
        if (choice == 4) SortPlaylist();
    }
}
