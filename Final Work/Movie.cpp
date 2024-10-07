#include "Movie.h"
#include <cstring>

// Construtor padrão
Movie::Movie() : adult(false), id(0), popularity(0.0), revenue(0.0), runtime(0.0), vote_average(0.0), vote_count(0) {
    memset(imdb_id, 0, sizeof(imdb_id));
    memset(original_language, 0, sizeof(original_language));
    memset(original_title, 0, sizeof(original_title));
    memset(overview, 0, sizeof(overview));
    memset(release_date, 0, sizeof(release_date));
    memset(title, 0, sizeof(title));
}

// Construtor com parâmetros
Movie::Movie(bool adult, int id, const char* imdb_id, const char* original_language, 
             const char* original_title, const char* overview, double popularity, 
             const char* release_date, double revenue, double runtime, 
             const char* title, double vote_average, int vote_count) 
    : adult(adult), id(id), popularity(popularity), revenue(revenue), runtime(runtime), 
      vote_average(vote_average), vote_count(vote_count) {
    
    strncpy(this->imdb_id, imdb_id, sizeof(this->imdb_id) - 1);
    strncpy(this->original_language, original_language, sizeof(this->original_language) - 1);
    strncpy(this->original_title, original_title, sizeof(this->original_title) - 1);
    strncpy(this->overview, overview, sizeof(this->overview) - 1);
    strncpy(this->release_date, release_date, sizeof(this->release_date) - 1);
    strncpy(this->title, title, sizeof(this->title) - 1);
}

// Getters
bool Movie::isAdult() const { return adult; }
int Movie::getId() const { return id; }
const char* Movie::getImdbId() const { return &imdb_id[0]; }
const char* Movie::getOriginalLanguage() const { return &original_language[0]; }
const char* Movie::getOriginalTitle() const { return &original_title[0]; }
const char* Movie::getOverview() const { return &overview[0]; }
double Movie::getPopularity() const { return popularity; }
const char* Movie::getReleaseDate() const { return &release_date[0]; }
double Movie::getRevenue() const { return revenue; }
double Movie::getRuntime() const { return runtime; }
const char* Movie::getTitle() const { return &title[0]; }
double Movie::getVoteAverage() const { return vote_average; }
int Movie::getVoteCount() const { return vote_count; }
const char* Movie::getGenres() const { return &genres[0]; }
const char* Movie::getProductionCompanies() const { return &production_companies[0]; }
const char* Movie::getProductionCountries() const { return &production_countries[0]; }
const char* Movie::getSpokenLanguages() const { return &spoken_languages[0]; }
int Movie::getBinaryIndex() const { return this->binaryIndex; }

// Setters
void Movie::setAdult(bool adult) { this->adult = adult; }
void Movie::setId(int id) { this->id = id; }
void Movie::setImdbId(const char* imdb_id) { strncpy(this->imdb_id, imdb_id, sizeof(this->imdb_id) - 1); }
void Movie::setOriginalLanguage(const char* original_language) { strncpy(this->original_language, original_language, sizeof(this->original_language) - 1); }
void Movie::setOriginalTitle(const char* original_title) { strncpy(this->original_title, original_title, sizeof(this->original_title) - 1); }
void Movie::setOverview(const char* overview) { strncpy(this->overview, overview, sizeof(this->overview) - 1); }
void Movie::setPopularity(double popularity) { this->popularity = popularity; }
void Movie::setReleaseDate(const char* release_date) { strncpy(this->release_date, release_date, sizeof(this->release_date) - 1); }
void Movie::setRevenue(double revenue) { this->revenue = revenue; }
void Movie::setRuntime(double runtime) { this->runtime = runtime; }
void Movie::setTitle(const char* title) { strncpy(this->title, title, sizeof(this->title) - 1); }
void Movie::setVoteAverage(double vote_average) { this->vote_average = vote_average; }
void Movie::setVoteCount(int vote_count) { this->vote_count = vote_count; }
void Movie::setBinaryIndex(int index) { this->binaryIndex = index; }

void Movie::setGenres(const char* genres, int size) {
    for (int i = 0; i < size; i++) { //&& i < 10
        this->genres[i] = genres[i];
    }
}

void Movie::setProductionCompanies(const char* production_companies, int size) {
    for (int i = 0; i < size; i++) { // && i < 100
        this->production_companies[i] = production_companies[i];
    }
}

void Movie::setProductionCountries(const char* production_countries, int size) {
    for (int i = 0; i < size; i++) { // && i < 100
        this->production_countries[i] = production_countries[i];
    }
}

void Movie::setSpokenLanguages(const char* spoken_languages, int size) {
    for (int i = 0; i < size; i++) { // && i < 100
        this->spoken_languages[i] = spoken_languages[i];
    }
}
