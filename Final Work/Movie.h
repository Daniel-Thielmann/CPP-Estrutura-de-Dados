#ifndef MOVIE_H__
#define MOVIE_H__


class Movie {
public:
    Movie();
    Movie(bool adult, int id, const char* imdb_id, const char* original_language, 
          const char* original_title, const char* overview, double popularity, 
          const char* release_date, double revenue, double runtime, 
          const char* title, double vote_average, int vote_count);

    // Getters
    bool isAdult() const;
    int getId() const;
    const char* getImdbId() const;
    const char* getOriginalLanguage() const;
    const char* getOriginalTitle() const;
    const char* getOverview() const;
    double getPopularity() const;
    const char* getReleaseDate() const;
    double getRevenue() const;
    double getRuntime() const;
    const char* getTitle() const;
    double getVoteAverage() const;
    int getVoteCount() const;
    const char* getGenres() const;
    const char* getProductionCompanies() const;
    const char* getProductionCountries() const;
    const char* getSpokenLanguages() const;
    int getBinaryIndex() const;

    // Setters
    void setAdult(bool adult);
    void setId(int id);
    void setImdbId(const char* imdb_id);
    void setOriginalLanguage(const char* original_language);
    void setOriginalTitle(const char* original_title);
    void setOverview(const char* overview);
    void setPopularity(double popularity);
    void setReleaseDate(const char* release_date);
    void setRevenue(double revenue);
    void setRuntime(double runtime);
    void setTitle(const char* title);
    void setVoteAverage(double vote_average);
    void setVoteCount(int vote_count);
    void setGenres(const char* genres, int size);
    void setProductionCompanies(const char* production_companies, int size);
    void setProductionCountries(const char* production_countries, int size);
    void setSpokenLanguages(const char* spoken_languages, int size);
    void setBinaryIndex(int index);

    static Movie* import (int n);


private:
    bool adult;
    char genres[200]; // Supondo um máximo de 10 gêneros
    int id;
    char imdb_id[10];
    char original_language[3];
    char original_title[200];
    char overview[1000];
    double popularity;
    char production_companies[200]; // Supondo um máximo de 100 empresas de produção
    char production_countries[200]; // Supondo um máximo de 100 países de produção
    char release_date[11]; // Formato "dd/mm/yyyy"
    double revenue;
    double runtime;
    char spoken_languages[200]; // Supondo um máximo de 10 idiomas falados
    char title[200];
    double vote_average;
    int vote_count;
    int binaryIndex;
};

#endif
