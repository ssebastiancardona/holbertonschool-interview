#!/usr/bin/node
const req = require('request');

async function sw (id) {
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  req(url, async (err, res, body) => {
    if (err) {
      console.log(err);
    } else {
      for (const c of JSON.parse(body).characters) {
        const sol = () => {
          return new Promise((resolve, reject) => {
            req(c, (err, res, body) => {
              if (err) {
                console.log(err);
              } else {
                resolve(JSON.parse(body).name);
              }
            });
          });
        };
        console.log(await sol());
      }
    }
  });
}

if (process.argv.length === 3) {
  sw(process.argv[2]);
}