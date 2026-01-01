
const searchInput = document.querySelector(".search-box input");
const searchBtn = document.querySelector(".search-box button");
const locationEl = document.querySelector(".location-date span:first-child");
const dateEl = document.querySelector(".location-date span:last-child");
const tempEl = document.querySelector("#temp");
const iconEl = document.querySelector("#icon");
const humidityEl = document.querySelector("#humidity");
const windEl = document.querySelector("#wind");
const forecastEls = document.querySelectorAll(".forecast .day");

function formatDate(dateStr) {
    const date = new Date(dateStr);
    return date.toLocaleDateString("en-US", {
        weekday: "short",
        day: "2-digit",
        month: "short"
    });
}


function setWeatherIcon(el, code) {
    if (!el) {
        return;
    }
    let iconClass = "fa-cloud";
    if (code === 0) {iconClass = "fa-sun";}
    else if (code <= 3) {
        iconClass = "fa-cloud-sun";
    }
    else if (code <= 48) {
        iconClass = "fa-smog";
    }
    else if (code <= 65) {
        iconClass = "fa-cloud-rain";
    }
    else if (code <= 77) {
        iconClass = "fa-snowflake";
    }
    else if (code <= 82) {
        iconClass = "fa-cloud-showers-heavy";
    }
    else{ iconClass = "fa-bolt";}
    el.className = `fa-solid ${iconClass}`;
}

async function getWeather(city) {
    try {
        const geoRes = await fetch(`https://geocoding-api.open-meteo.com/v1/search?name=${encodeURIComponent(city)}&count=1&language=en`);
        const geo = await geoRes.json();

        if (!geo.results || geo.results.length === 0) {
            alert("City not found  Please check spelling.");
            return;
        }

        const { latitude, longitude, name, admin1, country } = geo.results[0];
        
        locationEl.innerHTML = `📍 ${name}, ${admin1 || country}`;

        const weatherUrl = `https://api.open-meteo.com/v1/forecast?latitude=${latitude}&longitude=${longitude}&current=temperature_2m,relative_humidity_2m,wind_speed_10m,weather_code&daily=temperature_2m_max,weather_code&timezone=auto&wind_speed_unit=ms`;
        
        const weatherRes = await fetch(weatherUrl);
        const data = await weatherRes.json();

        if (data.current) {
            tempEl.textContent = Math.round(data.current.temperature_2m) + "°C";
            humidityEl.textContent = data.current.relative_humidity_2m + "%";
            windEl.textContent = data.current.wind_speed_10m.toFixed(1) + " m/s";

            setWeatherIcon(iconEl, data.current.weather_code);
            dateEl.textContent = formatDate(data.current.time);
        }

        if (data.daily) {
            forecastEls.forEach((day, i) => {
                const nextDayIndex = i + 1; 
                const date = data.daily.time[nextDayIndex];
                const temp = data.daily.temperature_2m_max[nextDayIndex];
                const code = data.daily.weather_code[nextDayIndex];

                if(date) {
                    day.querySelector(".date").textContent = formatDate(date);
                    day.querySelector(".temp").textContent = Math.round(temp) + "°C";
                    setWeatherIcon(day.querySelector(".weather-icon"), code);
                }
            });
        }

    } catch (err) {
        console.error("Error fetching weather:", err);
        alert("Server error. Please try again later.");
    }
}

searchBtn.addEventListener("click", () => {
    const city = searchInput.value.trim();
    if (city) getWeather(city);
});

searchInput.addEventListener("keyup", (e) => {
    if (e.key === "Enter") {
        const city = searchInput.value.trim();
        if (city) getWeather(city);
    }
});

