<template>
  <div class="header">
    <h1>{{Titulo}}</h1>
  </div>
</template>
<script>
export default {
  name: "HeaderComponent",
  props: {
    Titulo: String
  }
};
</script>

<style lang="scss" scoped>
.header {
  overflow: hidden;
  background-color: #f1f1f1;
  padding: 5px 5px;
}
</style>