#!/usr/bin/node
const request = require('request');

async function sw (id) {
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  request(url, async (err, res, body) => {
    if (err) {
      console.log(err);
    } else {
      for (const c of JSON.parse(body).characters) {
        const soll = () => {
          return new Promise((resolve, reject) => {
            request(c, (err, res, body) => {
              if (err) {
                console.log(err);
              } else {
                resolve(JSON.parse(body).name);
              }
            });
          });
        };
        console.log(await soll());
      }
    }
  });
}

if (process.argv.length === 3) {
  sw(process.argv[2]);
}