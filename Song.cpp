/*****************************************
** File:    Song.cpp
** Project: CMSC 202 Project 5, Fall 2025
** Author:  Amit Reddy
** Date:    11/18/2025
** Section: 32
** Email:   amitr2@@umbc.edu
**
** Description:
** Implements the Song class: constructors, getters, setters, and operator overloads.
*****************************************/

#include "Song.h"
using namespace std;

//-------------------------------------------------------
// Name: Song (Default Constructor)
// Desc: Creates a Song with empty strings and 0 streams.
// Preconditions: None
// Postconditions: All data members are initialized to default.
//-------------------------------------------------------
Song::Song() {
  m_title = "";
  m_album = "";
  m_artist = "";
  m_spotify = 0;
  m_youtube = 0;
  m_tiktok = 0;
}

// Desc: Initializes a Song with provided values.
Song::Song(string title, string album, string artist,
           long spotify, long youtube, long tiktok) {
  m_title = title;
  m_album = album;
  m_artist = artist;
  m_spotify = spotify;
  m_youtube = youtube;
  m_tiktok = tiktok;
}


// Desc: Returns the title of the Song.
string Song::GetTitle() const { return m_title; }


// Desc: Returns the album name.
string Song::GetAlbum() const { return m_album; }


// Desc: Returns the artist name.
string Song::GetArtist() const { return m_artist; }


// Desc: Returns Spotify stream count.
long Song::GetSpotify() const { return m_spotify; }

//Returns YouTube stream count.
long Song::GetYouTube() const { return m_youtube; }

// Returns TikTok stream count.
long Song::GetTikTok() const { return m_tiktok; }

//Updates data members.
void Song::SetTitle(string title)   { m_title = title; }
void Song::SetAlbum(string album)   { m_album = album; }
void Song::SetArtist(string artist) { m_artist = artist; }
void Song::SetSpotify(long spotify) { m_spotify = spotify; }
void Song::SetYouTube(long youtube) { m_youtube = youtube; }
void Song::SetTikTok(long tiktok)   { m_tiktok = tiktok; }


// Outputs Song info in formatted form.
ostream& operator<<(ostream& os, Song& song) {
  os << song.GetTitle() << " by " << song.GetArtist()
     << " from " << song.GetAlbum() << endl;
  return os;
}


// Compares Songs using Spotify streams.
bool Song::operator<(const Song& other) {
  return m_spotify < other.m_spotify;
}
