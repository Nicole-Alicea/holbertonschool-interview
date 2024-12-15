#!/usr/bin/node

/**
 * Script to fetch and display character names from a Star Wars film
 * using the SWAPI API (https://swapi-api.hbtn.io).
 *
 * Usage:
 *   node script.js <movieId>
 *
 * Example:
 *   node script.js 1
 *
 * Requirements:
 * - The `request` package must be installed (`npm install request`).
 * - The `movieId` parameter should be a valid film ID from the SWAPI API.
 */

const request = require('request');

// Get the movie ID from the command-line arguments
const movieId = process.argv[2];

if (!movieId) {
  console.error('Please provide a movie ID');
  process.exit(1); // Exit the script with a failure status
}

// Construct the API URL to fetch the film data
const apiUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

/**
 * Makes a request to the SWAPI API to get the film details.
 */
request(apiUrl, (error, response, body) => {
  if (error) {
    console.error('Error fetching API:', error);
    return;
  }

  // Check if the API returned a successful response
  if (response.statusCode !== 200) {
    console.error('Invalid movie ID');
    return;
  }

  // Parse the response body to JSON
  const data = JSON.parse(body);
  const characterUrls = data.characters;

  /**
   * Fetches the character name from a given URL.
   *
   * @param {string} url - The URL to the character's API endpoint.
   * @returns {Promise<string>} A promise that resolves to the character's name.
   */
  const fetchCharacterName = (url) => {
    return new Promise((resolve, reject) => {
      request(url, (error, response, body) => {
        if (error) {
          reject(error);
        } else {
          const characterData = JSON.parse(body);
          resolve(characterData.name);
        }
      });
    });
  };

  /**
   * Fetches and prints all character names for the film.
   * Uses asynchronous iteration to handle multiple requests sequentially.
   */
  const fetchAllCharacters = async () => {
    try {
      for (const url of characterUrls) {
        const name = await fetchCharacterName(url);
        console.log(name);
      }
    } catch (err) {
      console.error('Error fetching character names:', err);
    }
  };

  // Start fetching character names
  fetchAllCharacters();
});
