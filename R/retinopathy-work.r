# Autor: João Henrique Serodio Ulbinski
# Data: 07 de julho de 2025
# GitHub: jhserodio
# Email: me@serodio.dev

library(survival)
library(ggplot2)
library(dplyr)
library(moments)

output_dir <- "analise_retinopatia_resultados"
if (!dir.exists(output_dir)) {
  dir.create(output_dir)
}

data(retinopathy, package = "survival")

retinopathy <- retinopathy %>%
  mutate(
    laser = factor(laser, levels = c("xenon", "argon")),
    eye = factor(eye, levels = c("right", "left")),
    type = factor(type, levels = c("juvenile", "adult")),
    trt = factor(trt, levels = c("0", "1"), labels = c("Controle", "Tratado")),
    status = factor(status, levels = c("0", "1"), labels = c("Censurado", "Perda de Visão"))
  )

plot_laser <- ggplot(retinopathy, aes(x = laser, fill = laser)) +
  geom_bar() +
  labs(
    title = "Distribuição do Tipo de Laser Utilizado",
    x = "Tipo de Laser",
    y = "Contagem"
  ) +
  theme_minimal() +
  scale_fill_brewer(palette = "Set2")
ggsave(filename = file.path(output_dir, "plot_laser.png"), plot = plot_laser, width = 6, height = 4, dpi = 300)

plot_eye <- ggplot(retinopathy, aes(x = eye, fill = eye)) +
  geom_bar() +
  labs(
    title = "Distribuição do Olho Tratado",
    x = "Olho",
    y = "Contagem"
  ) +
  theme_minimal() +
  scale_fill_brewer(palette = "Paired")
ggsave(filename = file.path(output_dir, "plot_eye.png"), plot = plot_eye, width = 6, height = 4, dpi = 300)

plot_type <- ggplot(retinopathy, aes(x = type, fill = type)) +
  geom_bar() +
  labs(
    title = "Distribuição do Tipo de Diabetes",
    x = "Tipo de Diabetes",
    y = "Contagem"
  ) +
  theme_minimal() +
  scale_fill_brewer(palette = "Dark2")
ggsave(filename = file.path(output_dir, "plot_type.png"), plot = plot_type, width = 6, height = 4, dpi = 300)

plot_trt <- ggplot(retinopathy, aes(x = trt, fill = trt)) +
  geom_bar() +
  labs(
    title = "Distribuição do Grupo de Tratamento",
    x = "Grupo",
    y = "Contagem"
  ) +
  theme_minimal() +
  scale_fill_manual(values = c("Controle" = "#E69F00", "Tratado" = "#56B4E9"))
ggsave(filename = file.path(output_dir, "plot_trt.png"), plot = plot_trt, width = 6, height = 4, dpi = 300)

plot_status <- ggplot(retinopathy, aes(x = status, fill = status)) +
  geom_bar() +
  labs(
    title = "Distribuição do Status da Perda de Visão",
    x = "Status",
    y = "Contagem"
  ) +
  theme_minimal() +
  scale_fill_manual(values = c("Censurado" = "#999999", "Perda de Visão" = "#D55E00"))
ggsave(filename = file.path(output_dir, "plot_status.png"), plot = plot_status, width = 6, height = 4, dpi = 300)

plot_age_hist <- ggplot(retinopathy, aes(x = age)) +
  geom_histogram(binwidth = 5, fill = "skyblue", color = "black") +
  labs(
    title = "Distribuição da Idade no Diagnóstico de Diabetes",
    x = "Idade (anos)",
    y = "Frequência"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_age_hist.png"), plot = plot_age_hist, width = 6, height = 4, dpi = 300)

plot_age_boxplot <- ggplot(retinopathy, aes(y = age)) +
  geom_boxplot(fill = "lightgreen") +
  labs(
    title = "Boxplot da Idade no Diagnóstico",
    y = "Idade (anos)"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_age_boxplot.png"), plot = plot_age_boxplot, width = 4, height = 6, dpi = 300)

plot_futime_hist <- ggplot(retinopathy, aes(x = futime)) +
  geom_histogram(binwidth = 10, fill = "salmon", color = "black") +
  labs(
    title = "Distribuição do Tempo de Acompanhamento/Perda de Visão",
    x = "Tempo (meses)",
    y = "Frequência"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_futime_hist.png"), plot = plot_futime_hist, width = 6, height = 4, dpi = 300)

plot_futime_boxplot <- ggplot(retinopathy, aes(y = futime)) +
  geom_boxplot(fill = "violet") +
  labs(
    title = "Boxplot do Tempo de Acompanhamento/Perda de Visão",
    y = "Tempo (meses)"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_futime_boxplot.png"), plot = plot_futime_boxplot, width = 4, height = 6, dpi = 300)

plot_risk_hist <- ggplot(retinopathy, aes(x = risk)) +
  geom_histogram(binwidth = 1, fill = "gold", color = "black") +
  labs(
    title = "Distribuição da Pontuação de Risco",
    x = "Pontuação de Risco",
    y = "Frequência"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_risk_hist.png"), plot = plot_risk_hist, width = 6, height = 4, dpi = 300)

plot_risk_boxplot <- ggplot(retinopathy, aes(y = risk)) +
  geom_boxplot(fill = "orange") +
  labs(
    title = "Boxplot da Pontuação de Risco",
    y = "Pontuação de Risco"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_risk_boxplot.png"), plot = plot_risk_boxplot, width = 4, height = 6, dpi = 300)

plot_age_futime_scatter <- ggplot(retinopathy, aes(x = age, y = futime)) +
  geom_point(alpha = 0.6, color = "darkblue") +
  labs(
    title = "Relação entre Idade e Tempo de Acompanhamento",
    x = "Idade no Diagnóstico",
    y = "Tempo de Acompanhamento (meses)"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_age_futime_scatter.png"), plot = plot_age_futime_scatter, width = 7, height = 5, dpi = 300)

plot_age_futime_type <- ggplot(retinopathy, aes(x = age, y = futime, color = type)) +
  geom_point(alpha = 0.7) +
  labs(
    title = "Idade vs. Tempo de Acompanhamento por Tipo de Diabetes",
    x = "Idade no Diagnóstico",
    y = "Tempo de Acompanhamento (meses)",
    color = "Tipo de Diabetes"
  ) +
  theme_minimal()
ggsave(filename = file.path(output_dir, "plot_age_futime_type.png"), plot = plot_age_futime_type, width = 8, height = 5, dpi = 300)

calculate_descriptive_stats <- function(data, var_name) {
  var_vec <- data[[var_name]]
  var_vec <- as.numeric(na.omit(var_vec))
  if (length(var_vec) == 0) {
    return(NULL)
  }
  mean_val <- mean(var_vec)
  sd_val <- sd(var_vec)
  var_val <- var(var_vec)
  cv_val <- (sd_val / mean_val) * 100
  quantiles_val <- quantile(var_vec, probs = c(0.25, 0.50, 0.75))
  deciles_val <- quantile(var_vec, probs = seq(0.1, 0.9, by = 0.1))
  percentiles_val <- quantile(var_vec, probs = c(0.01, 0.05, 0.10, 0.90, 0.95, 0.99))
  skewness_val <- skewness(var_vec)
  kurtosis_val <- kurtosis(var_vec)
  output_string <- c(
    paste("--- Estatísticas Descritivas para '", var_name, "' ---", sep = ""),
    paste("Nº de Observações:", length(var_vec)),
    paste("Média:", round(mean_val, 2)),
    paste("Variância:", round(var_val, 2)),
    paste("Desvio Padrão:", round(sd_val, 2)),
    paste("Coeficiente de Variação (CV):", paste0(round(cv_val, 2), "%")),
    "",
    "Quartis:",
    paste("  25% (Q1):", round(quantiles_val["25%"], 2)),
    paste("  50% (Mediana/Q2):", round(quantiles_val["50%"], 2)),
    paste("  75% (Q3):", round(quantiles_val["75%"], 2)),
    "",
    "Decis:",
    paste("  10% (D1):", round(deciles_val["10%"], 2)),
    paste("  20% (D2):", round(deciles_val["20%"], 2)),
    paste("  30% (D3):", round(deciles_val["30%"], 2)),
    paste("  40% (D4):", round(deciles_val["40%"], 2)),
    paste("  50% (D5):", round(deciles_val["50%"], 2)),
    paste("  60% (D6):", round(deciles_val["60%"], 2)),
    paste("  70% (D7):", round(deciles_val["70%"], 2)),
    paste("  80% (D8):", round(deciles_val["80%"], 2)),
    paste("  90% (D9):", round(deciles_val["90%"], 2)),
    "",
    "Percentis Chave:",
    paste("  1%:", round(percentiles_val["1%"], 2)),
    paste("  5%:", round(percentiles_val["5%"], 2)),
    paste("  10%:", round(percentiles_val["10%"], 2)),
    paste("  90%:", round(percentiles_val["90%"], 2)),
    paste("  95%:", round(percentiles_val["95%"], 2)),
    paste("  99%:", round(percentiles_val["99%"], 2)),
    "",
    paste("Assimetria:", round(skewness_val, 3)),
    paste("Curtose:", round(kurtosis_val, 3)),
    "\n"
  )
  return(output_string)
}

stats_age_text <- calculate_descriptive_stats(retinopathy, "age")
if (!is.null(stats_age_text)) {
  writeLines(stats_age_text, file.path(output_dir, "stats_age.txt"))
}

stats_futime_text <- calculate_descriptive_stats(retinopathy, "futime")
if (!is.null(stats_futime_text)) {
  writeLines(stats_futime_text, file.path(output_dir, "stats_futime.txt"))
}

stats_risk_text <- calculate_descriptive_stats(retinopathy, "risk")
if (!is.null(stats_risk_text)) {
  writeLines(stats_risk_text, file.path(output_dir, "stats_risk.txt"))
}
