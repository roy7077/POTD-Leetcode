class FoodRatings {
    public:
    unordered_map<string, map<int, set<string>>> cuisine2rateAndFood;
    unordered_map<string, pair<int, string>> food2cuisineAndRate;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            cuisine2rateAndFood[cuisines[i]][ratings[i]].insert(foods[i]);
            food2cuisineAndRate[foods[i]] = make_pair(ratings[i], cuisines[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [prevRating, cuisine] = food2cuisineAndRate[food];
        cuisine2rateAndFood[cuisine][prevRating].erase(food);
        if (cuisine2rateAndFood[cuisine][prevRating].empty()) {
            cuisine2rateAndFood[cuisine].erase(prevRating);
        }
        cuisine2rateAndFood[cuisine][newRating].insert(food);
        
        food2cuisineAndRate[food].first = newRating;
    }
    
    string highestRated(string cuisine) {
        auto foodSet = cuisine2rateAndFood[cuisine].rbegin()->second;
        return *foodSet.begin();
    }
};
