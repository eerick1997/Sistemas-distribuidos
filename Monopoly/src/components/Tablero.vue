<template>
  <!-- <div class="hello">
    <h1>Mi tablero</h1>
  </div>-->
  <div class="table" id="main">
    <div class="board">
      <div class="center">
        <div class="community-chest-deck">
          <h2 class="label">Community Chest</h2>
          <div class="deck"></div>
        </div>
        <h1 class="title">MONOPOLY</h1>
        <div class="chance-deck">
          <h2 class="label">Chance</h2>
          <div class="deck"></div>
        </div>
      </div>

      <div class="space corner go">
        <div class="container">
          <div class="instructions">Collect $200.00 salary as you pass</div>
          <div class="go-word">go</div>
        </div>
        <div class="arrow fa fa-long-arrow-left"></div>
      </div>

      <div class="row horizontal-row bottom-row">
        <div class="space property">
          <div class="container">
            <div class="color-bar light-blue"></div>
            <div class="name">Connecticut Avenue</div>
            <div class="price">PRICE $120</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar light-blue"></div>
            <div class="name">Vermont Avenue</div>
            <div class="price">Price $100</div>
          </div>
        </div>
        <div class="space chance">
          <div class="container">
            <div class="name">Chance</div>
            <i class="drawing fa fa-question"></i>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar light-blue"></div>
            <div class="name">Oriental Avenue</div>
            <div class="price">Price $100</div>
          </div>
        </div>
        <div class="space railroad">
          <div class="container">
            <div class="name">Reading Railroad</div>
            <i class="drawing fa fa-subway"></i>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space fee income-tax">
          <div class="container">
            <div class="name">Income Tax</div>
            <div class="diamond"></div>
            <div class="instructions">
              Pay 10%
              <br />or
              <br />$200
            </div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar dark-purple"></div>
            <div class="name">Baltic Avenue</div>
            <div class="price">Price $50</div>
          </div>
        </div>
        <div class="space community-chest">
          <div class="container">
            <div class="name">Community Chest</div>
            <i class="drawing fa fa-cube"></i>
            <div class="instructions">Follow instructions on top card</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar dark-purple"></div>
            <div class="name three-line-name">
              Mediter-
              <br />ranean
              <br />Avenue
            </div>
            <div class="price">Price $50</div>
          </div>
        </div>
      </div>

      <div class="space corner jail">
        <div class="just">Just</div>
        <div class="drawing">
          <div class="container">
            <div class="name">In</div>
            <div class="window">
              <div class="bar"></div>
              <div class="bar"></div>
              <div class="bar"></div>
              <i class="person far fa-frown"></i>
            </div>
            <div class="name">Jail</div>
          </div>
        </div>
        <div class="visiting">Visiting</div>
      </div>

      <div class="row vertical-row left-row">
        <div class="space property">
          <div class="container">
            <div class="color-bar orange"></div>
            <div class="name">New York Avenue</div>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar orange"></div>
            <div class="name">Tennessee Avenue</div>
            <div class="price">Price $180</div>
          </div>
        </div>
        <div class="space community-chest">
          <div class="container">
            <div class="name">Community Chest</div>
            <i class="drawing fa fa-cube"></i>
            <div class="instructions">Follow instructions on top card</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar orange"></div>
            <div class="name">St. James Avenue</div>
            <div class="price">Price $180</div>
          </div>
        </div>
        <div class="space railroad">
          <div class="container">
            <div class="name long-name">Pennsylvania Railroad</div>
            <i class="drawing fa fa-subway"></i>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar purple"></div>
            <div class="name">Virginia Avenue</div>
            <div class="price">Price $160</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar purple"></div>
            <div class="name">States Avenue</div>
            <div class="price">Price $140</div>
          </div>
        </div>
        <div class="space utility electric-company">
          <div class="container">
            <div class="name">Electric Company</div>
            <i class="drawing fa fa-lightbulb-o"></i>
            <div class="price">Price $150</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar purple"></div>
            <div class="name">St. Charles Place</div>
            <div class="price">Price $140</div>
          </div>
        </div>
      </div>

      <div class="space corner free-parking">
        <div class="container">
          <div class="name">Free</div>
          <i class="drawing fa fa-car"></i>
          <div class="name">Parking</div>
        </div>
      </div>

      <div class="row horizontal-row top-row">
        <div class="space property">
          <div class="container">
            <div class="color-bar red"></div>
            <div class="name">Kentucky Avenue</div>
            <div class="price">Price $220</div>
          </div>
        </div>
        <div class="space chance">
          <div class="container">
            <div class="name">Chance</div>
            <i class="drawing fa fa-question blue"></i>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar red"></div>
            <div class="name">Indiana Avenue</div>
            <div class="price">Price $220</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar red"></div>
            <div class="name">Illinois Avenue</div>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space railroad">
          <div class="container">
            <div class="name">B & O Railroad</div>
            <i class="drawing fa fa-subway"></i>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar yellow"></div>
            <div class="name">Atlantic Avenue</div>
            <div class="price">Price $260</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar yellow"></div>
            <div class="name">Ventnor Avenue</div>
            <div class="price">Price $260</div>
          </div>
        </div>
        <div class="space utility waterworks">
          <div class="container">
            <div class="name">Waterworks</div>
            <i class="drawing fa fa-tint"></i>
            <div class="price">Price $120</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar yellow"></div>
            <div class="name">Marvin Gardens</div>
            <div class="price">Price $280</div>
          </div>
        </div>
      </div>

      <div class="space corner go-to-jail">
        <div class="container">
          <div class="name">Go To</div>
          <i class="drawing fa fa-gavel"></i>
          <div class="name">Jail</div>
        </div>
      </div>

      <div class="row vertical-row right-row">
        <div class="space property">
          <div class="container">
            <div class="color-bar green"></div>
            <div class="name">Pacific Avenue</div>
            <div class="price">Price $300</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar green"></div>
            <div class="name three-line-name">North Carolina Avenue</div>
            <div class="price">Price $300</div>
          </div>
        </div>
        <div class="space community-chest">
          <div class="container">
            <div class="name">Community Chest</div>
            <i class="drawing fa fa-cube"></i>
            <div class="instructions">Follow instructions on top card</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar green"></div>
            <div class="name long-name">Pennsylvania Avenue</div>
            <div class="price">Price $320</div>
          </div>
        </div>
        <div class="space railroad">
          <div class="container">
            <div class="name">Short Line</div>
            <i class="drawing fa fa-subway"></i>
            <div class="price">Price $200</div>
          </div>
        </div>
        <div class="space chance">
          <div class="container">
            <div class="name">Chance</div>
            <i class="drawing fa fa-question"></i>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar dark-blue"></div>
            <div class="name">Park Place</div>
            <div class="price">Price $350</div>
          </div>
        </div>
        <div class="space fee luxury-tax">
          <div class="container">
            <div class="name">Luxury Tax</div>
            <div class="drawing fa fa-diamond"></div>
            <div class="instructions">Pay $75.00</div>
          </div>
        </div>
        <div class="space property">
          <div class="container">
            <div class="color-bar dark-blue"></div>
            <div class="name">Boardwalk</div>
            <div class="price">Price $400</div>
          </div>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "Tablero"
};
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang="scss">
// =================
// TYPOGRAPHY
// =================

$body-font: "Oswald", sans-serif;

// =================
// COLORS
// =================

$black: #080808;
$brown: #640303;
$board: #fafaf8;
$dark-purple: #5e3577;
$light-blue: #d2eaf5;
$purple: #b02f7c;
$orange: #fa811d;
$red: #f50c2b;
$yellow: #ffed20;
$green: #41994e;
$dark-blue: #5a6dba;

// =================
// GLOBAL
// =================

* {
  box-sizing: border-box;
}

#main {
  margin: 0;
  // background-image: url("https://i.pinimg.com/originals/a4/73/cd/a473cda6c0a58d9b2e2bc2292d16c334.jpg");
  // background-position: center;
  // background-repeat: repeat;
  //background-size: 100px;
  font-family: $body-font;
  font-weight: 400;
  font-size: 10px;
  color: $black;
  text-transform: uppercase;
}

h1,
h2,
h3,
h4,
h5,
h6 {
  margin: 0;
}

// Property colors

.dark-purple {
  background: $dark-purple;
}
.light-blue {
  background: $light-blue;
}
.purple {
  background: $purple;
}
.orange {
  background: $orange;
}
.red {
  background: $red;
}
.yellow {
  background: $yellow;
}
.green {
  background: $green;
}
.dark-blue {
  background: $dark-blue;
}

// =================
// LAYOUT
// =================

// Table and board

.table {
  padding-left: 50px;
  padding-right: 50px;
}

.board {
  display: grid;
  grid-template-columns: 125px repeat(9, 80px) 125px;
  grid-template-rows: 125px repeat(9, 80px) 125px;
  grid-gap: 2px;
  margin: 50px auto;
  width: 994px;
  height: 994px;
  background: $black;
  border: 2px solid $black;
}

.center {
  grid-column: 2 / 11;
  grid-row: 2 / 11;
  background: $board;
  display: grid;
  grid-template-columns: repeat(7, 1fr);
  grid-template-rows: repeat(7, 1fr);
  justify-items: center;
  align-items: center;
}

.title {
  grid-column: 1 / 9;
  grid-row: 4;
  font-size: 90px;
  font-weight: 400;
  letter-spacing: 12px;
}

.community-chest-deck {
  grid-column: 2 / 4;
  grid-row: 2 / 4;
  transform: rotate(135deg);
  margin-bottom: 60px;
  margin-right: 60px;
}

.chance-deck {
  grid-column: 5 / 7;
  grid-row: 5 / 7;
  transform: rotate(315deg);
  margin-top: 60px;
  margin-left: 60px;
}

.label {
  text-align: center;
  font-weight: 500;
  letter-spacing: 3px;
  padding-bottom: 10px;
}

.deck {
  border: 2px dashed $black;
  width: 160px;
  height: 120px;
}

// Rows of spaces

.row {
  display: grid;
  grid-gap: 2px;
}

.horizontal-row {
  grid-template-columns: repeat(9, 80px);
  grid-template-rows: 125px;
}

.vertical-row {
  grid-template-columns: 125px;
  grid-template-rows: repeat(9, 80px);

  .container {
    top: 50%;
    left: 50%;
  }
}

.bottom-row {
  grid-column: 2 / 11;
  grid-row: 11;
}

.left-row {
  grid-column: 1;
  grid-row: 2 / 11;

  .container {
    transform: translate(-50%, -50%) rotate(90deg);
  }
}

.top-row {
  grid-column: 2 / 11;
  grid-row: 1;

  .container {
    transform: rotate(180deg);
  }
}

.right-row {
  grid-column: 11;
  grid-row: 2 / 11;

  .container {
    transform: translate(-50%, -50%) rotate(270deg);
  }
}

// =================
// SPACES
// =================

// Types of spaces

.space {
  background: $board;
  text-align: center;

  .container {
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    position: relative;
    transform-origin: center;
    height: 125px;
    width: 80px;
  }

  .name,
  .instructions {
    padding-left: 15px;
    padding-right: 15px;
  }

  .price {
    font-size: 7px;
    font-weight: 400;
    padding-bottom: 5px;
  }
}

.corner {
  .container {
    justify-content: space-around;
    height: 100%;
    width: 100%;
  }

  .name {
    padding: 0;
  }
}

.property {
  .color-bar {
    height: 25px;
    border-bottom: 2px solid $black;
  }

  .name {
    padding-bottom: 50px;
  }
}

.railroad {
  .name {
    padding-top: 10px;
  }

  .drawing {
    font-size: 60px;
    color: $black;
  }
}

.utility {
  .name {
    padding-top: 10px;
  }

  .drawing {
    font-size: 70px;
  }
}

.fee {
  .name {
    padding-top: 10px;
    font-size: 14px;
  }

  .instructions {
    font-size: 10px;
  }
}

// Specific spaces

.go {
  grid-column: 11;
  grid-row: 11 / 12;
  position: relative;

  .container {
    justify-content: flex-start;
    transform: rotate(315deg);
  }

  .instructions {
    padding: 0 30px;
  }

  .go-word {
    font-size: 60px;
    color: $red;
  }

  .arrow {
    font-size: 45px;
    color: $red;
    position: absolute;
    bottom: -10px;
    left: 5px;
  }
}

.jail {
  grid-column: 1;
  grid-row: 11 / 12;
  display: grid;
  grid-template-columns: repeat(10, 12.5px);
  grid-template-rows: repeat(10, 12.5px);
  justify-content: center;
  align-items: center;

  .drawing {
    grid-column: 4 / 11;
    grid-row: 1 / 8;
    width: 87.5px;
    height: 87.5px;
    background: $orange;
    border-bottom: 2px solid $black;
    border-left: 2px solid $black;
  }

  .just {
    grid-column: 3;
    grid-row: 4;
    transform: rotate(90deg);
    padding-top: 5px;
  }

  .visiting {
    grid-column: 6;
    grid-row: 8;
    padding-top: 5px;
  }

  .container {
    align-items: center;
    transform: rotate(45deg);
  }

  .name {
    font-size: 14px;
  }

  .window {
    display: flex;
    justify-content: space-around;
    align-items: center;
    position: relative;
    width: 55px;
    height: 55px;
    background: $board;
    border: 2px solid $black;
  }

  .person {
    position: absolute;
    transform: translate(-50%, -50%);
    top: 50%;
    left: 50%;
    font-size: 40px;
  }

  .bar {
    height: 55px;
    width: 2px;
    background: $black;
  }
}

.free-parking {
  grid-column: 1;
  grid-row: 1 / 2;

  .container {
    justify-content: center;
    transform: rotate(135deg);
  }

  .name {
    font-size: 16px;
  }

  .drawing {
    font-size: 60px;
    color: $red;
    padding-top: 5px;
    padding-bottom: 5px;
  }
}

.go-to-jail {
  grid-column: 11;
  grid-row: 1 / 1;

  .container {
    justify-content: center;
    transform: rotate(225deg);
  }

  .name {
    font-size: 16px;
  }

  .drawing {
    font-size: 60px;
    color: $brown;
    padding-top: 5px;
    padding-bottom: 5px;
  }
}

.chance {
  .container {
    justify-content: center;
  }

  .drawing {
    font-size: 90px;
    color: $red;
  }

  .blue {
    color: $dark-blue;
  }
}

.community-chest {
  .container {
    justify-content: space-around;
  }

  .drawing {
    font-size: 50px;
    color: $light-blue;
  }

  .instructions {
    font-size: 8px;
  }
}

.electric-company {
  .drawing {
    color: $yellow;
  }
}

.waterworks {
  .drawing {
    color: $dark-blue;
  }
}

.income-tax {
  .container {
    justify-content: center;
    align-items: center;
  }

  .name {
    padding-bottom: 5px;
  }

  .diamond {
    width: 5px;
    height: 5px;
    background: $black;
    transform: rotate(45deg);
    display: inline-block;
  }

  .instructions {
    padding-top: 5px;
    padding-bottom: 5px;
  }
}

.luxury-tax {
  .drawing {
    font-size: 50px;
  }

  .instructions {
    padding-bottom: 5px;
  }
}

// =================
// UTILITY
// =================

.long-name {
  padding-left: 0 !important;
  padding-right: 0 !important;
}

.three-line-name {
  position: relative;
  top: 5px;
}
</style>
