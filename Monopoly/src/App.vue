<template>
  <div id="app">
    <HeaderComponent Titulo="Juego Monopoly" />
    <Tablero />
    <UserInformation />
  </div>
</template>

<script>
import Tablero from "./components/Tablero.vue";
import HeaderComponent from "./components/HeaderComponent";
import UserInformation from "./components/UserInformation";

export default {
  name: "app",
  components: {
    Tablero,
    HeaderComponent,
    UserInformation
  }
};
</script>

<style lang="scss">
html,
body {
  margin: 0;
  padding: 0;
}
#app {
  font-family: "Avenir", Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin: 0;
}
</style>
