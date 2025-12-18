import matplotlib.pyplot as plt
import pandas as pd

# Data setup
data = {
    "years": ["2010-11", "2011-12", "2012-13", "2013-14", "2014-15", "2015-16", "2016-17", "2017-18",
              "2018-19", "2019-20", "2020-21", "2021-22", "2022-23", "2023-24", "2024-25"],
    "official_growth": [None, None, 1, 3, 7, -1, 2, 6, 7, 2, -5, 23, 6, 10, 10],
    "cpi_growth": [None, None, 0, 2, 11, 6, 5, 6, 9, -1, -6, 14, 1, 4, 6],
    "wpi_growth": [None, None, 3, 5, 11, 4, 7, 8, 8, -2, -3, 13, 7, 8, 9]
}
df = pd.DataFrame(data)

# Color and marker style
colors = ['#1FB8CD', '#DB4545', '#2E8B57']
markers = ['o', 'D', 's']

# Create the plot
plt.figure(figsize=(12, 6))

plt.plot(df['years'], df['official_growth'], label='Official (Defl)', marker=markers[0], color=colors[0], linewidth=2)
plt.plot(df['years'], df['cpi_growth'], label='CPI Based', marker=markers[1], color=colors[1], linewidth=2)
plt.plot(df['years'], df['wpi_growth'], label='WPI Based', marker=markers[2], color=colors[2], linewidth=2)

# Titles and labels
plt.title('Real GDP Growth: Defl v CPI v WPI (10–25)', fontsize=14)
plt.xlabel('Year')
plt.ylabel('Growth %')

plt.xticks(rotation=45)
plt.grid(True, axis='y', linestyle='--', alpha=0.5)

plt.legend(loc='upper center', bbox_to_anchor=(0.5, 1.12), ncol=3)
plt.tight_layout()

# Save and show
plt.savefig('real_gdp_growth_matplotlib.png', dpi=300)
plt.show()
