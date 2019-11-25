module.exports = {
    devServer: {
        host: "0.0.0.0",
        port: 3000,
        https: false,
        hotOnly: false,
        proxy: {
            "/api": {
                target: "https://localhost:8080",
                ws: true,
                changeOrigin: true
            }
        }
    }
};