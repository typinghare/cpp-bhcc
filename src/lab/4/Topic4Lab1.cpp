/**
 * @author Zhuojian Chen (James)
 * @date Mar 7, 2022
*/

#include <iostream>
#include <string>

using namespace std;

/**
 * @requirement
 * Given the attached structure, design a program (pseudocode is great for this) for the gallery to
 * receive work for the show, display work for the show, sell work, and determine how much $$ the
 * gallery makes and each artist makes (broken down by tax and sale).
 */

struct ArtWork {
    string artistName;
    string media;   // I don't really understand what does this attribute means
    string artWorkName;
    double length;
    double width;
    double price;
    string artistEmail;
    bool didSell = false;
    short galleryID;
};

struct Show {
    // all art works to display on the show
    ArtWork *artWorkArray;

    // required because arrays do not tell the size of itself in C++
    int artworkNumber;
};

struct Gallery {
    double revenue = 0;
};

struct Artist {
    double revenue = 0;
};


const double TAX_RATE = 0.0625;
const double GALLERY_REBATE_RATE = 0.40;

/**s
 * Prints information of all works displayed in the show.
 * @param show
 */
void printArtWorkInfo(Show show) {
}

/**
 * Sells an art work. The gallery and artist of the art work increase revenue.
 */
void sellArtWork(ArtWork artWork, Gallery gallery, Artist artist) {
    double price = artWork.price;
    // I am not good at economics, should it be calculated like this?
    gallery.revenue += price * (1 - TAX_RATE);
    artist.revenue += price * (1-TAX_RATE) * (1 - GALLERY_REBATE_RATE);
    artWork.didSell = true;
}

/**
 * Returns the revenue of the gallery.
 */
double getGalleryRevenue(Gallery gallery) {
    return gallery.revenue;
}

/**
 * Returns the revenue of the artist.
 */
double getArtistRevenue(Artist artist) {
    return artist.revenue;
}

int main() {
    const int ART_WORK_NUMBER = 10;

    Show show;
    show.artWorkArray = new ArtWork[ART_WORK_NUMBER];
    show.artworkNumber = 10;

    // here collect all galleryIDs from the art works and create a gallery array
    // suppose there are three different galleries
    const int GALLERY_NUMBER = 3;
    Gallery *galleryArray = new Gallery[GALLERY_NUMBER];

    // artist of those art works
    // here I should create a map of (artist name => artist instance),
    // but I don't know how to create a map in C++
    // Java: final Map<String, Artist> artistMap = new HashMap<>();
    const int ARTIST_NUMBER = 5;
    Artist *artistArray = new Artist[ARTIST_NUMBER];

    printArtWorkInfo(show);

    // sell an art work
    ArtWork artWorkToSell = show.artWorkArray[0];
    sellArtWork(artWorkToSell, galleryArray[artWorkToSell.galleryID], artistArray[0]);

    // print the revenue of galleries
    for (int i = 0; i < GALLERY_NUMBER; ++i) {
        cout << getGalleryRevenue(galleryArray[i]) << endl;
    }

    // print the revenue of the artists
    for (int i = 0; i < ARTIST_NUMBER; ++i) {
        cout << getArtistRevenue(artistArray[i]) << endl;
    }

    // release
    delete[] show.artWorkArray;
    delete[] galleryArray;

    return 0;
}